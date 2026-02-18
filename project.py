import tkinter as tk
from tkinter import messagebox
from datetime import datetime
import os
from PIL import Image, ImageTk

users = {}
last_mood = None

# -------- SAVE & LOAD USERS --------
def load_users():
    if os.path.exists("users.txt"):
        with open("users.txt", "r") as f:
            for line in f:
                username, password, sap = line.strip().split(",")
                users[username] = (password, sap)

def save_user(username, password, sap):
    with open("users.txt", "a") as f:
        f.write(f"{username},{password},{sap}\n")

load_users()

# ---------------- LOGIN ----------------
def login():
    username = entry_user.get()
    password = entry_pass.get()

    if username == "" or password == "":
        messagebox.showerror("Error", "Fill all fields!")
        return

    if username in users and users[username][0] == password:
        root.destroy()
        open_main(username)
    else:
        messagebox.showerror("Error", "Invalid login!")

def create_account():
    username = entry_user.get()
    password = entry_pass.get()
    sap_id = entry_sap.get()

    if username == "" or password == "" or sap_id == "":
        messagebox.showerror("Error", "Fill all fields!")
        return

    if username in users:
        messagebox.showerror("Error", "Account already exists!")
    else:
        users[username] = (password, sap_id)
        save_user(username, password, sap_id)
        messagebox.showinfo("Success", "Account created!")

# ---------------- LOGIN WINDOW ----------------
root = tk.Tk()
root.title("Login")
root.geometry("400x350")
root.configure(bg="#e6f2ff")

tk.Label(root, text="Username", bg="#e6f2ff").pack(pady=5)
entry_user = tk.Entry(root)
entry_user.pack()

tk.Label(root, text="Password", bg="#e6f2ff").pack(pady=5)
entry_pass = tk.Entry(root, show="*")
entry_pass.pack()

tk.Label(root, text="SAP ID", bg="#e6f2ff").pack(pady=5)
entry_sap = tk.Entry(root)
entry_sap.pack()

tk.Button(root, text="Login", bg="#4da6ff", fg="white", command=login).pack(pady=5)
tk.Button(root, text="Create Account", bg="#4da6ff", fg="white", command=create_account).pack()

# ---------------- MAIN APP ----------------
def open_main(username):
    global last_mood

    app = tk.Tk()
    app.title("Mind Track")
    app.geometry("520x620")
    app.configure(bg="#e6f2ff")

    file_name = f"{username}_chat.txt"

    # -------- TOP --------
    top_frame = tk.Frame(app, bg="#4da6ff")
    top_frame.pack(fill="x")

    tk.Label(top_frame, text="Mind Track",
             font=("Arial", 18, "bold"),
             bg="#4da6ff", fg="white").pack(pady=2)

    tk.Label(top_frame,
             text="Navya Agarwal | Ishanvi Kalra",
             font=("Arial", 11, "bold"),
             bg="#4da6ff", fg="white").pack()

    tk.Label(top_frame,
             text="SAP ID: 590024522 | 590025196",
             font=("Arial", 10),
             bg="#4da6ff", fg="white").pack()

    time_label = tk.Label(top_frame, bg="#4da6ff", fg="white")
    time_label.pack()

    def update_time():
        now = datetime.now()
        time_label.config(text=now.strftime("%d-%m-%Y %H:%M:%S"))
        app.after(1000, update_time)

    update_time()

    tk.Button(top_frame, text="Exit", command=app.destroy).pack(side="right", padx=10)

    # -------- PHOTO --------
    frame_photo = tk.Frame(app, bg="#e6f2ff")
    frame_photo.pack(pady=5)

    try:
        img = Image.open("photo.png")   # keep image in same folder
        img = img.resize((120, 120))
        photo = ImageTk.PhotoImage(img)

        label_img = tk.Label(frame_photo, image=photo, bg="#e6f2ff")
        label_img.image = photo
        label_img.pack()
    except:
        tk.Label(frame_photo, text="Image not found!", bg="#e6f2ff").pack()

    # -------- CHAT --------
    frame_chat = tk.Frame(app)
    frame_chat.pack()

    scrollbar = tk.Scrollbar(frame_chat)
    scrollbar.pack(side="right", fill="y")

    chat_box = tk.Text(frame_chat, height=20, width=60,
                       bg="#f0f8ff", yscrollcommand=scrollbar.set)
    chat_box.pack()

    scrollbar.config(command=chat_box.yview)

    # LOAD OLD CHAT
    if os.path.exists(file_name):
        with open(file_name, "r") as f:
            chat_box.insert(tk.END, f.read())

    # START MESSAGE
    now = datetime.now().strftime("%d-%m-%Y %H:%M")
    chat_box.insert(tk.END, f"[{now}] Bot: Hi 😊 how are you?\n\n")

    # -------- CHAT FUNCTION --------
    def send(event=None):
        global last_mood

        user_text = entry.get().strip()
        if user_text == "":
            return

        now = datetime.now().strftime("%d-%m-%Y %H:%M")

        user_msg = f"[{now}] You: {user_text}\n"
        chat_box.insert(tk.END, user_msg, "user")

        text = user_text.lower()

        if text == "sad":
            reply = "Kya hua? bata na..."
            last_mood = "sad"

        elif text == "happy":
            reply = "Nice 😄 kya hua?"
            last_mood = "happy"

        elif text == "confused":
            reply = "Kya confusion hai?"
            last_mood = "confused"

        elif last_mood == "sad":
            reply = "Tension mat lo, sab theek ho jayega 💪"
            last_mood = None

        elif last_mood == "happy":
            reply = "Great 🔥 happy for you!"
            last_mood = None

        elif last_mood == "confused":
            reply = "Step by step socho 👍 solve ho jayega"
            last_mood = None

        else:
            reply = "Aur bata… main sun rahi hu"

        bot_msg = f"[{now}] Bot: {reply}\n\n"
        chat_box.insert(tk.END, bot_msg, "bot")

        chat_box.tag_config("user", foreground="blue")
        chat_box.tag_config("bot", foreground="green")

        with open(file_name, "a") as f:
            f.write(user_msg)
            f.write(bot_msg)

        entry.delete(0, tk.END)
        chat_box.see(tk.END)

    # INPUT
    entry = tk.Entry(app, width=40)
    entry.pack(pady=5)

    entry.bind("<Return>", send)

    tk.Button(app, text="Send",
              bg="#4da6ff", fg="white",
              font=("Arial", 10, "bold"),
              command=send).pack()

    app.mainloop()

root.mainloop()