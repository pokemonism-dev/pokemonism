/**
 * The "I Have a Dream" Protocol
 * Version 19.63
 *
 * @author Martin Luther King Jr.
 * @license Creative Commons (For all of God's children)
 */
class AmericanDream {
  constructor() {
    // "...a promissory note to which every American was to fall heir."
    this.promissoryNote = new Promise((resolve, reject) => {
      const nation = new BankOfJustice();
      if (nation.hasSufficientFunds()) {
        resolve('the riches of freedom and security of justice');
      } else {
        // "...a check that has come back marked 'insufficient funds.'"
        reject(new Error('Insufficient Funds'));
      }
    });

    this.dreams = [
      { description: 'that one day this nation will rise up and live out the true meaning of its creed: "We hold these truths to be self-evident that all men are created equal."' },
      { description: 'that one day out in the red hills of Georgia the sons of former slaves and the sons of former slaveowners will be able to sit down together at the table of brotherhood.' },
      { description: 'that my four little children will one day live in a nation where they will not be judged by the color of their skin but by their character.' },
      { description: 'that one day every valley shall be engulfed, every hill shall be exalted and every mountain shall be made low.' },
    ];
  }

  /**
   * "So we have come to cash this check..."
   * This is the main execution block of the protocol.
   */
  async marchOnWashington() {
    try {
      // Attempt to cash the check based on the original promise.
      const freedom = await this.promissoryNote;
      console.log('Promise honored:', freedom);
    } catch (error) {
      // "But we refuse to believe that the bank of justice is bankrupt."
      console.warn('Initial check failed:', error.message);
      console.log('Refusing to believe. Engaging the fierce urgency of Now.');

      // "Tell them about your dream, Martin!"
      // An external event triggers the real dream.
      this.tellThemAboutTheDream();
    }
  }

  /**
   * The core of the speech, turning a failed promise into a new vision.
   */
  async tellThemAboutTheDream() {
    console.log('I still have a dream. It is a dream deeply rooted in the American dream.');

    // The dream is a collection of promises that must all be fulfilled.
    const dreamPromises = this.dreams.map(dream => {
      return new Promise(resolve => {
        console.log(`I have a dream ${dream.description}`);
        // Each dream is a task to be completed.
        resolve(true);
      });
    });

    // Wait for all dreams to be realized.
    await Promise.all(dreamPromises);

    // "With this faith we will be able to hew out of the mountain of despair a stone of hope."
    this.letFreedomRing();
  }

  /**
   * "...from every mountainside, let freedom ring!"
   */
  letFreedomRing() {
    const locations = [
      'the hilltops of New Hampshire',
      'the mighty mountains of New York',
      'the heightening Alleghenies of Pennsylvania',
      'the snow-capped Rockies of Colorado',
      'the curvaceous slopes of California',
      'Stone Mountain of Georgia',
      'every hill and molehill of Mississippi',
    ];

    locations.forEach(location => {
      console.log(`Let freedom ring from ${location}!`);
    });

    this.finallyFree();
  }

  /**
   * The final resolution.
   */
  finallyFree() {
    console.log('\nFree at last, free at last. Thank God Almighty, we are free at last.');
  }
}
