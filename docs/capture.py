
# This is a simple, "not cool" script to capture conversations.

capture_file = "./docs/capture.tmp"
memory_file = "./docs/memory.md"

try:
    # 1. Read the new content from the temporary capture file
    with open(capture_file, "r", encoding="utf-8") as f:
        new_content = f.read()

    # 2. Append the new content to the permanent memory log
    with open(memory_file, "a", encoding="utf-8") as f:
        f.write("\n\n---\n\n") # Add a separator
        f.write(new_content)

    # 3. Erase the temporary file's content to prevent duplicates
    with open(capture_file, "w", encoding="utf-8") as f:
        f.write("")

    print("✅ Conversation captured to memory.md. The capture.tmp file is now empty.")

except FileNotFoundError:
    print(f"❌ Error: Capture file not found at {capture_file}")
    print("👉 Please paste the conversation into that file first.")
except Exception as e:
    print(f"An unexpected error occurred: {e}")
