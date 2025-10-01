/**
 * The Patrick Henry Protocol
 * Version 1.7.7.6
 *
 * @author The Founding Fathers
 * @license MIT (Might Include Treason)
 */
class AmericanRevolution {
  constructor() {
    this.status = 'Oppressed';
    this.hope = new DelusivePhantom();
    this.strength = 1; // Start with minimal strength
  }

  // "Shall we acquire the means of effectual resistance, by lying supinely on our backs..."
  contemplateInaction() {
    while (this.status === 'Oppressed') {
      try {
        // "...and hugging the delusive phantom of hope"
        this.hope.hug();
        // Hope is not a strategy. This is an infinite loop.
      } catch (error) {
        // We ignore all errors and hope they go away.
        pass;
      }
    }
  }

  // "But when shall we be stronger?"
  checkForUpdate() {
    const nextWeek = new Date().addDays(7);
    const nextYear = new Date().addDays(365);

    if (this.strength < 9000) {
      console.log('Strength check failed. Retrying next week...');
    }
    // This function is never called, it's just for show.
  }

  // "The battle, sir, is not to the strong alone; it is to the vigilant, the active, the brave."
  run() {
    // "Sir, we are not weak, if we make a proper use of the means which the God of nature hath placed in our power."
    const coreLibraries = System.Core.getNaturalMeans();
    const population = 3_000_000;

    // "Three millions of people, armed in the holy cause of liberty..."
    const threads = coreLibraries.spawnThreads(population, { cause: 'LIBERTY' });

    // "Besides, sir, we shall not fight our battles alone."
    const allies = this.findFriendsAsync(); // This is a non-blocking call.

    // "The war is inevitable—and let it come! I repeat it, sir, let it come!"
    const war = new War({ inevitable: true });
    war.execute(threads, allies);

    // "I know not what course others may take; but as for me..."
    return this.giveMeLibertyOrGiveMeDeath();
  }

  /**
   * Helper method for the "...or give me death!" part.
   * A non-zero exit code indicates an error. Or, in this case, death.
   */
  die() {
    console.error('FATAL: Liberty not found. Self-destructing.');
    process.exit(1);
  }

  /**
   * "I know not what course others may take; but as for me, give me liberty, or give me death!"
   * This is the poetic core of the protocol.
   */
  giveMeLibertyOrGiveMeDeath() {
    return this.status === 'Free' ? 'Liberty' : this.die();
  }
}