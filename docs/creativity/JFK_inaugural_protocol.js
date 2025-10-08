/**
 * The JFK Inaugural Protocol
 * Version 19.61
 *
 * @author John F. Kennedy
 * @license Ask not what your country can do for you...
 */
class NewFrontier {
  constructor() {
    // "...the torch has been passed to a new generation of Americans..."
    this.torch = new Torch({
      holder: 'New Generation',
      properties: ['tempered by war', 'disciplined by a hard and bitter peace', 'proud of our ancient heritage'],
    });
  }

  /**
   * The core principle of the New Frontier.
   * This method inverts the traditional relationship between a system and its user.
   * It does not provide a service; it requests one.
   *
   * @param {Citizen} citizen The user of the system.
   * @returns The result of the citizen's contribution.
   */
  ask(citizen) {
    // "ask not what your country can do for you..."
    // We explicitly reject any requests for services.
    if (citizen.expectsService()) {
      throw new Error('Invalid request: Ask not what your country can do for you.');
    }

    // "...ask what you can do for your country."
    // We invoke the citizen's contribution method.
    const contribution = citizen.whatICanDoForMyCountry();
    this.processContribution(contribution);
    return `Thank you for your contribution: ${contribution}`;
  }

  processContribution(contribution) {
    // "...unwilling to witness or permit the slow undoing of those human rights..."
    if (contribution.violates(HumanRights.getUniversalDeclaration())) {
      throw new Error('Contribution rejected: Violates fundamental human rights.');
    }
    console.log(`Processing contribution: ${contribution}...`);
  }
}

// A conceptual representation of a citizen object.
class Citizen {
  constructor(serviceRequest, contribution) {
    this.serviceRequest = serviceRequest;
    this.contribution = contribution;
  }

  expectsService() {
    return this.serviceRequest !== null;
  }

  whatICanDoForMyCountry() {
    return this.contribution;
  }
}
