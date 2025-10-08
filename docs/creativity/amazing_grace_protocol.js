/**
 * The Amazing Grace Protocol
 * Version 20.15
 *
 * @author Barack Obama & The Emanuel AME Church Congregation
 * @license Grace (Unearned and Freely Given)
 */
class CollectiveHealing {
  constructor(attendees) {
    this.status = 'overwhelmingGrief';
    this.attendees = attendees; // A Set of all individuals present
    this.speech = new Speech({ topic: 'Grace' });
  }

  /**
   * The main entry point for the protocol.
   * It starts as a formal speech but transforms into something else.
   */
  async deliverEulogy() {
    // The planned part of the event.
    this.speech.deliver();

    // "...he paused for a long moment..."
    await this.pauseReflectively(13000); // A long, 13-second pause.

    // This is not a planned method call. This is a miracle.
    // The President steps out of his role and becomes a fellow mourner.
    this.singAmazingGrace();
  }

  /**
   * The moment of alchemy, where logic fails and a song begins.
   * This is a broadcast event, not a function with a return value.
   */
  singAmazingGrace() {
    console.log('President: Amazing Grace, how sweet the sound...');
    this.status = 'surprisedSilence';

    // The song acts as a signal that ripples through the crowd.
    // It breaks the established protocol of a eulogy.
    this.attendees.forEach(person => {
      person.listenForMiracle(this);
    });
  }

  /**
   * The response from the collective.
   * @param {string} newVoice The voice of the person joining the chorus.
   */
  joinChorus(newVoice) {
    // The first few voices joining in turn the silence into a chorus.
    if (this.status === 'surprisedSilence') {
      this.status = 'collectiveSinging';
      console.log('The congregation rises. A chorus begins.');
    }
    // console.log(`${newVoice} joins the song.`);
  }

  /**
   * The final state of the system.
   * The protocol does not return a value. It changes the state of the world.
   */
  resolve() {
    if (this.status === 'collectiveSinging') {
      this.status = 'sharedHope';
      console.log('\nThe hall is filled not with grief, but with a shared sense of grace and hope.');
    }
  }
}

// A conceptual representation of an attendee.
class Attendee {
  constructor(name) {
    this.name = name;
    this.status = 'grieving';
  }

  listenForMiracle(protocol) {
    // When the song begins, the individual's state changes, and they join the collective.
    this.status = 'singing';
    protocol.joinChorus(this.name);
  }
}
