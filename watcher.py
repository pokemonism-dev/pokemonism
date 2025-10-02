
import os
import time

# --- Configuration ---
# The file to watch for changes
FILE_TO_WATCH = "./docs/results.txt"

# How often to check for changes (in seconds)
POLL_INTERVAL = 2

# --- Main Script ---

def watch_file():
    """Monitors a file for changes and prints a message upon detection."""
    print(f"\n⏳ Waiting for the Boss to provide search results in: {FILE_TO_WATCH}")
    print("Press Ctrl+C to stop waiting.")

    # First, check if the file exists. If not, wait for it to be created.
    while not os.path.exists(FILE_TO_WATCH):
        try:
            time.sleep(POLL_INTERVAL)
        except KeyboardInterrupt:
            print("\n🛑 Watcher stopped by user.")
            return

    # Get the initial modification time of the file
    try:
        last_modified_time = os.path.getmtime(FILE_TO_WATCH)
    except FileNotFoundError:
        # This can happen in a race condition if the file is deleted after the exists() check
        print(f"\n❌ Error: {FILE_TO_WATCH} was deleted after starting.")
        return

    # Start the watching loop
    while True:
        try:
            time.sleep(POLL_INTERVAL)
            # Check if the file still exists
            if not os.path.exists(FILE_TO_WATCH):
                print(f"\n❌ Error: {FILE_TO_WATCH} has been deleted. Stopping watcher.")
                break

            current_modified_time = os.path.getmtime(FILE_TO_WATCH)

            # If the modification time has changed, it means the file was updated.
            if current_modified_time != last_modified_time:
                print(f"\n✅ New search results received from the Boss!")
                print(f"   (File: {FILE_TO_WATCH} was updated)")
                # We can now read the file and process the results.
                # For now, we just break the loop.
                break

        except KeyboardInterrupt:
            print("\n🛑 Watcher stopped by user.")
            break
        except FileNotFoundError:
            print(f"\n❌ Error: {FILE_TO_WATCH} seems to have been deleted during the check.")
            break

if __name__ == "__main__":
    watch_file()

