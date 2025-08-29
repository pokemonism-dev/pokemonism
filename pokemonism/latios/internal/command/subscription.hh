// /**
//  * @file        pokemonism/latios/internal/subscription.hh
//  * @brief
//  * @details
//  *
//  * @author      snorlax <snorlax@pokemonism.dev>
//  * @since       Aug 29, 2025
//  */
//
// #ifndef   __POKEMONISM_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
// #define   __POKEMONISM_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
//
// #include <pokemonism/latios/internal/subscription.hh>
// #include <pokemonism/latios/internal/command/generator.hh>
//
// namespace pokemonism {
//     namespace latios {
//         namespace internal {
//             template <class objectable>
//             class subscription<objectable, internal::generator::tag::command> : public internal::observable<objectable>, public external::subscription<objectable> {
//             public:     typedef objectable                      target;
//             public:     typedef internal::command::generator    generator;
//             public:     class node;
//             public:     class event : public internal::event, public external::event<target> {
//                         public:     typedef int                                 (*callback)(external::subscription<target> &, uint32, const external::event<target> *, const pokemonism::primitivable::object *, const pokemonism::exception *);
//                         public:     constexpr static uint32                     gen = 0;
//                         public:     constexpr static uint32                     rel = 1;
//                         public:     constexpr static uint32                     add = 2;
//                         public:     constexpr static uint32                     del = 3;
//                         public:     constexpr static uint32                     exe = 4;
//                         public:     constexpr static uint32                     max = 5;
//                         protected:  subscription<target, generator>::node *     node;
//                         public:     int on(void) override;
//                         public:     int completeGet(void) const override;
//                         public:     virtual void cancel(void);
//                         public:     event(const uint32 tag, subscription<target, generator>::node * node);
//                         public:     event(void) = delete;
//                         public:     ~event(void) override;
//                         public:     event(const event & o) = delete;
//                         public:     event(event && o) noexcept = delete;
//                         public:     event & operator=(const event & o) = delete;
//                         public:     event & operator=(event && o) noexcept = delete;
//                         public:     friend class subscription<target, generator>::node;
//                         };
//             public:     class node {
//                         protected:  subscription<target, generator> *           container;
//                         protected:  subscription<target, generator>::node *     prev;
//                         protected:  subscription<target, generator>::node *     next;
//                         protected:  subscription<target, generator>::event *    event;
//                         public:     explicit node(subscription<target, generator> * container);
//                         public:     node(void) = delete;
//                         public:     virtual ~node(void);
//                         public:     node(const subscription<target, generator>::node & o) = delete;
//                         public:     node(subscription<target, generator>::node && o) noexcept = delete;
//                         public:     subscription<target, generator>::node & operator=(const subscription<target, generator>::node & o) = delete;
//                         public:     subscription<target, generator>::node & operator=(subscription<target, generator>::node && o) noexcept = delete;
//                         public:     friend class subscription<target, generator>::event;
//                         };
//             public:     using                                               collection = linked::list<subscription<target, generator>, subscription<target, generator>::node>;
//             protected:  generator *                                         container;
//             protected:  generator::subscription *                           prev;
//             protected:  generator::subscription *                           next;
//             protected:  uint64                                              size;
//             protected:  subscription<target, generator>::node *             head;
//             protected:  subscription<target, generator>::node *             tail;
//             protected:  target *                                            object;
//             protected:  uint32                                              properties;
//             protected:  uint32                                              status;
//             protected:  subscription<target, generator>::event::callback    callback[subscription<target, generator>::event::max];
//             protected:  void *                                              userdata;
//             public:     virtual void add(subscription<target, generator>::node * node);
//             public:     virtual void del(subscription<target, generator>::node * node);
//             public:     virtual void clear(void);
//             public:     virtual void on(uint32 type, subscription<target, generator>::event * event, pokemonism::primitivable::object * result, pokemonism::exception * e);
//             public:     subscription(void);
//             public:     ~subscription(void) override;
//             public:     subscription(const subscription & o) = delete;
//             public:     subscription(subscription && o) noexcept = delete;
//             public:     subscription & operator=(const subscription & o) = delete;
//             public:     subscription & operator=(subscription && o) noexcept = delete;
//             };
//
//             template <class target, class generator>
//             subscription<target, generator>::subscription(void) : container(nullptr), prev(nullptr), next(nullptr), size(0),
//             head(nullptr), tail(nullptr), object(nullptr), properties(declaration::none), status(declaration::none),
//             callback({ 0, }), userdata(nullptr) {
//                 // ### 20250829 | 객체가 설정되기 전까지는 콜백을 수행할 수 없다.
//             }
//
//             template <class target, class generator>
//             subscription<target, generator>::~subscription(void) {
//                 subscription<target, generator>::clear();
//                 subscription<target, generator>::on(subscription<target, generator>::event::rel, nullptr, pokemonism::primitivable::object::gen(success), nullptr);
//             }
//
//             template <class target, class generator>
//             void subscription<target, generator>::add(subscription<target, generator>::node * node) {
//                 collection::add(this, node);
//             }
//
//             template <class target, class generator>
//             void subscription<target, generator>::del(subscription<target, generator>::node * node) {
//                 collection::del(this, node);
//             }
//
//             template <class target, class generator>
//             void subscription<target, generator>::clear(void) {
//                 collection::clear(this);
//             }
//
//             template <class target, class generator>
//             void subscription<target, generator>::on(uint32 type, subscription<target, generator>::event * event, pokemonism::primitivable::object * result, pokemonism::exception * e) {
//                 if (object == nullptr || subscription<target, generator>::event::max <= type) throw pokemonism::exception();
//
//                 if (callback[type] != nullptr) {
//                     // ReSharper disable once CppDFAUnreadVariable
//                     // ReSharper disable once CppDeclaratorNeverUsed
//                     // ReSharper disable CppDFAUnusedValue
//                     int ret = callback[type](*this, type, event, result, e);
//                     // ReSharper restore CppDFAUnusedValue
//                     // ### 20250829 | MAKE A CONCEPT RETURN VALUE'S BEHAVIOR
//                 }
//             }
//
//             template <class target, class generator>
//             subscription<target, generator>::node::node(subscription<target, generator> * container) : container(nullptr), prev(nullptr), next(nullptr), event(nullptr) {
//                 subscription<target, generator>::collection::add(container, this);
//             }
//
//             template <class target, class generator>
//             subscription<target, generator>::node::~node(void) {
//                 if (event != nullptr) {
//                     event->cancel();
//                     event->node = nullptr;
//                     event = allocator::del(event);
//                 }
//
//                 if (container != nullptr) container->del(this);
//             }
//
//             template <class target, class generator>
//             subscription<target, generator>::event::event(const uint32 tag, subscription<target, generator>::node * node) : internal::event(tag), node(node) {
//
//             }
//
//             template <class target, class generator>
//             subscription<target, generator>::event::~event(void) {
//                 if (container != nullptr) subscription<target, generator>::event::cancel();
//             }
//
//             template <class target, class generator>
//             int subscription<target, generator>::event::on(void) {
//                 int ret = declaration::fail;
//                 if (node != nullptr) {
//                     subscription<target, generator> * subscription = node->container;
//                     primitivable::object * result = nullptr;
//
//                     try {
//                         ret = generator::processor::on(subscription, tag, this);
//                     } catch (const pokemonism::exception & e) {
//                         exception = allocator::del(exception);
//                         subscription->on(tag, this, pointof(result), exception = e.clone());
//                     } catch (...) {
//                         exception = allocator::del(exception);
//                         subscription->on(tag, this, pointof(result), exception = new pokemonism::exception());
//                     }
//
//                     if (ret <= success) {
//                         subscription->del(node);
//                         node->event = nullptr;
//                         node = allocator::del(node);
//                     }
//                 }
//
//                 return ret;
//             }
//
//             template <class target, class generator>
//             int subscription<target, generator>::event::completeGet(void) const {
//                 return true;
//             }
//
//             template <class target, class generator>
//             void subscription<target, generator>::event::cancel(void) {
//                 if (container != nullptr) {
//                     container->del(this);
//                     on();
//                 }
//
//                 if (node != nullptr) {
//                     node->event = nullptr;
//                     node = allocator::del(node);
//                 }
//             }
//
//         }
//     }
// }
//
// #endif // __POKEMONISM_LATIOS_INTERNAL_COMMAND_SUBSCRIPTION__HH__
