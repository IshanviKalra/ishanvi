import tkinter as tk
from tkinter import messagebox
from datetime import datetime
import os

# ---------- USER SYSTEM ----------

def user_exists(username):
    try:
        with open("users.txt", "r") as f:
            for line in f:
                if username == line.split(",")[0]:
                    return True
    except:
        return False
    return False


def register():
    username = user_entry.get()
    password = pass_entry.get()

    if username == "" or password == "":
        messagebox.showwarning("Error", "Fill all fields")
        return

    if user_exists(username):
        messagebox.showerror("Error", "Username already exists!")
    else:
        with open("users.txt", "a") as f:
            f.write(f"{username},{password}\n")
        messagebox.showinfo("Success", "Account created!")
        open_main(username)


def login():
    username = user_entry.get()
    password = pass_entry.get()

    try:
        with open("users.txt", "r") as f:
            for line in f:
                u, p = line.strip().split(",")
                if username == u and password == p:
                    messagebox.showinfo("Success", "Login successful!")
                    open_main(username)
                    return
    except:
        pass

    messagebox.showerror("Error", "Invalid login")


# ---------- MAIN APP ----------

def open_main(username):
    root.destroy()

    main = tk.Tk()
    main.title("Mood Calendar")
    main.geometry("500x650")
    main.configure(bg="#1e1e2f")

    tk.Label(main, text=f"Welcome {username} 💙",
             font=("Arial", 16, "bold"),
             bg="#1e1e2f", fg="white").pack(pady=10)

    file_name = f"{username}_moods.txt"

    display = tk.Text(main, height=8, width=45,
                      bg="#2e2e3f", fg="white")
    display.pack(pady=10)

    # Load old data
    if os.path.exists(file_name):
        with open(file_name, "r") as f:
            display.insert(tk.END, f.read())
    else:
        display.insert(tk.END, "No previous data\n")

    # ---------- REAL CALENDAR ----------
    tk.Label(main, text="Select Date:",
             bg="#1e1e2f", fg="white",
             font=("Arial", 12, "bold")).pack(pady=5)

    cal_frame = tk.Frame(main, bg="#1e1e2f")
    cal_frame.pack(pady=10)

    selected_date = tk.StringVar()

    days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]

    for i, day in enumerate(days):
        tk.Label(cal_frame, text=day,
                 bg="#1e1e2f", fg="white",
                 font=("Arial", 10, "bold"),
                 width=5).grid(row=0, column=i)

    row = 1
    col = 0

    for i in range(1, 31):
        def select_day(day=i):
            selected_date.set(day)
            messagebox.showinfo("Selected", f"Date: {day}")

        btn = tk.Button(cal_frame,
                        text=str(i),
                        width=5, height=2,
                        bg="#3a3a5c", fg="white",
                        font=("Arial", 10, "bold"),
                        command=select_day)

        btn.grid(row=row, column=col, padx=3, pady=3)

        col += 1
        if col > 6:
            col = 0
            row += 1

    # ---------- MOOD INPUT ----------
    tk.Label(main, text="Enter Mood:",
             bg="#1e1e2f", fg="white").pack(pady=5)

    mood_entry = tk.Entry(main)
    mood_entry.pack()

    def save_mood():
        mood = mood_entry.get()
        day = selected_date.get()

        if mood == "" or day == "":
            messagebox.showwarning("Error", "Select date and enter mood")
            return

        date = f"{datetime.now().strftime('%Y-%m')}-{day}"

        if mood.lower() == "happy":
            emoji = "😄"
        elif mood.lower() == "sad":
            emoji = "😢"
        elif mood.lower() == "stressed":
            emoji = "😣"
        else:
            emoji = "🙂"

        with open(file_name, "a") as f:
            f.write(f"{date} : {mood} {emoji}\n")

        display.insert(tk.END, f"{date} : {mood} {emoji}\n")

        ask_chat(mood)

    def ask_chat(mood):
        if messagebox.askyesno("Chat", "Do you want to talk?"):
            if mood.lower() == "sad":
                messagebox.showinfo("Chat", "I'm here ❤️ tell me everything")
            elif mood.lower() == "happy":
                messagebox.showinfo("Chat", "That's amazing 😄")
            elif mood.lower() == "stressed":
                messagebox.showinfo("Chat", "Take a deep breath 🧘")
            else:
                messagebox.showinfo("Chat", "I'm listening 🙂")

    tk.Button(main, text="Save Mood",
              command=save_mood,
              bg="#4CAF50", fg="white").pack(pady=10)

    main.mainloop()


# ---------- LOGIN WINDOW ----------

root = tk.Tk()
root.title("Login")
root.geometry("350x300")
root.configure(bg="#121212")

tk.Label(root, text="Login / Signup",
         font=("Arial", 16, "bold"),
         bg="#121212", fg="white").pack(pady=10)

tk.Label(root, text="Username",
         bg="#121212", fg="white").pack()
user_entry = tk.Entry(root)
user_entry.pack()

tk.Label(root, text="Password",
         bg="#121212", fg="white").pack()
pass_entry = tk.Entry(root, show="*")
pass_entry.pack()

tk.Button(root, text="Login",
          command=login,
          bg="#2196F3", fg="white").pack(pady=5)

tk.Button(root, text="Create Account",
          command=register,
          bg="#FF9800", fg="white").pack(pady=5)

root.mainloop()