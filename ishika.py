import time
from datetime import datetime
import platform

# For beep sound
if platform.system() == "Windows":
    import winsound

tasks = []

def add_task():
    name = input("Enter task name: ")
    time_str = input("Enter time (YYYY-MM-DD HH:MM:SS): ")

    try:
        task_time = datetime.strptime(time_str, "%Y-%m-%d %H:%M:%S")
        tasks.append({"name": name, "time": task_time, "done": False})
        print(" Task added successfully!\n")
    except:
        print(" Invalid format! Use YYYY-MM-DD HH:MM:SS\n")

def view_tasks():
    if not tasks:
        print("No tasks available.\n")
        return

    print("\n Your Tasks:")
    for i, task in enumerate(tasks):
        status = "Done" if task["done"] else "Pending"
        print(f"{i+1}. {task['name']} - {task['time']} [{status}]")
    print()

def check_reminders():
    current_time = datetime.now()

    for task in tasks:
        if not task["done"] and current_time >= task["time"]:
            # Console popup style
            print("\n" + "="*30)
            print(f"REMINDER: {task['name']} is due now!")
            print("="*30 + "\n")

            # Beep once
            if platform.system() == "Windows":
                winsound.Beep(1000, 500)  # frequency, duration(ms)
            else:
                print("\a")  # fallback beep for Linux/Mac terminals

            task["done"] = True

def main():
    print("⏳ Workflow Automation System Started...\n")

    while True:
        check_reminders()  # ALWAYS checking

        print("====== MENU ======")
        print("1. Add Task")
        print("2. View Tasks")
        print("3. Exit")

        choice = input("Enter choice: ")

        if choice == "1":
            add_task()
        elif choice == "2":
            view_tasks()
        elif choice == "3":
            print("Exiting system...")
            break
        else:
            print("Invalid choice!\n")

        time.sleep(1)  # check every second

if __name__ == "__main__":
    main()