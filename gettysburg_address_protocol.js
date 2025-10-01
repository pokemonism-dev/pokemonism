/**
 * The Gettysburg Address Protocol
 * Version 18.63
 *
 * @author Abraham Lincoln
 * @license Public Domain (of the people, by the people, for the people)
 */
class Nation {
  constructor() {
    this.conceivedIn = 'Liberty';
    this.isDedicatedTo = (man) => man.isCreatedEqual; // A function that always returns true.
    this.status = 'engagedInGreatCivilWar';
    this.battlefield = new Battlefield('Gettysburg');
  }

  // "But, in a larger sense, we can not dedicate, we can not consecrate, we can not hallow this ground."
  dedicateGround() {
    console.log('Attempting to dedicate ground...');
    const dedicationPower = 0.1; // Our poor power

    // "The brave men, living and dead, who struggled here, have consecrated it, far above our poor power to add or detract."
    if (this.battlefield.isConsecratedBy(BraveMen.livingAndDead) > dedicationPower) {
      throw new Error('Cannot dedicate. The ground is already consecrated by a higher power.');
    }
  }

  // "The world will little note, nor long remember what we say here..."
  say(speech) {
    // The output is immediately garbage-collected.
    return null;
  }

  // "...but it can never forget what they did here."
  remember(action) {
    // This action is written to a permanent, read-only memory block.
    Memory.write(action, { permanent: true });
  }

  /**
   * The main execution block of the protocol.
   * "It is for us the living, rather, to be dedicated here to the unfinished work..."
   */
  run() {
    const honoredDead = this.battlefield.getHonoredDead();
    const unfinishedWork = honoredDead.getUnfinishedWork();

    // "...that from these honored dead we take increased devotion to that cause..."
    this.devotion = this.devotion + honoredDead.getLastFullMeasureOfDevotion();

    // "...that we here highly resolve that these dead shall not have died in vain..."
    const promise = new Promise((resolve, reject) => {
      if (unfinishedWork.isCompleted) {
        resolve('The dead have not died in vain.');
      } else {
        reject('The dead have died in vain.');
      }
    });

    // "...that this nation, under God, shall have a new birth of freedom..."
    promise.then(() => {
      this.status = 'newBirthOfFreedom';
    });

    // "...and that government of the people, by the people, for the people, shall not perish from the earth."
    const government = new Government({ of: 'people', by: 'people', for: 'people' });
    if (government.isPerished()) {
      throw new Error('System Failure: Government has perished.');
    }

    return government;
  }
}
