/**
 * @file
 * @brief
 * @details
 * 
 * @author          snorlax <snorlax@pokemonism.dev>
 * @since           9월 06, 2025
 */


#include "subscription.hh"

namespace pokemonism::sdk {

    void command::event::subscription::callbackOn(unsigned int type, pokemonism::sdk::event::envelope & envelope, const pokemonism::sdk::event::exception * problem) {
        pokemon_develop_check(type != command::event::type::execute || dynamic_cast<command::event::envelope *>(pointof(envelope)) == nullptr, return);

        if (exception == nullptr && problem != nullptr) {
            status = status | command::event::subscription::state::exception;
            exception = problem->clone();
        }

        if (eventSet.execute) {
            command::event::link * result = static_cast<command::event::link *>(reinterpret_cast<void *>(pointof(envelope)));
            eventSet.execute(*object, type, *result, problem);
        }
    }

    void command::event::subscription::callbackOn(unsigned int type, const pokemonism::sdk::event::exception * problem) {
        pokemon_develop_check(type != command::event::type::execute, return);

        if (exception == nullptr && problem != nullptr) {
            status = status | command::event::subscription::state::exception;
            exception = problem->clone();
        }

        if (eventSet.execute) {
            command::event::envelope envelope(this);

            eventSet.execute(*object, type, envelope, problem);
        }
    }

    int command::event::subscription::processOn(pokemonism::sdk::event::link * link) {
        pokemon_develop_check(link == nullptr || dynamic_cast<command::event::link *>(link) == nullptr || link->identifierGet() != command::event::type::execute, return declaration::fail);

        int ret;
        command::event::link * node = reinterpret_cast<command::event::link *>(link);
        const unsigned int type = link->identifierGet();

        try {
            ret = command::event::processor::executeOn(*this, type, node);
        } catch (const pokemonism::sdk::exception & e) {
            if (node->exceptionGet() == nullptr) node->exceptionSet(e.clone());

            callbackOn(type, *node, pointof(e));

            container->del(this);

            return declaration::fail;
        } catch (...) {
            pokemonism::sdk::exception * e = new pokemonism::sdk::exception();

            callbackOn(type, *node, e);

            e = node->exceptionSet(e);

            if (e != nullptr) delete e;

            container->del(this);

            return declaration::fail;
        }

        callbackOn(type, *node);

        if (completeChk() || exceptionChk()) container->del(this);

        return ret;
    }

    int command::event::subscription::processOn(unsigned int type) {
        pokemon_develop_check(type != command::event::type::execute, return declaration::fail);

        int ret;

        try {
            ret = command::event::processor::executeOn(*this, type);
        } catch (const pokemonism::sdk::exception & e) {
            status = status | command::event::subscription::state::exception;
            stateOn(command::event::subscription::state::type::chk, pointof(e));

            return declaration::fail;
        } catch (...) {
            if (exception == nullptr) {
                status = status | command::event::subscription::state::exception;
                exception = new pokemonism::sdk::exception();
                stateOn(command::event::subscription::state::type::chk, exception);

                return declaration::fail;
            }

            const pokemonism::sdk::exception problem;
            status = status | command::event::subscription::state::exception;
            stateOn(command::event::subscription::state::type::chk, pointof(problem));

            return declaration::fail;
        }

        return ret;
    }



}