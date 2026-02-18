#write code for oops
import tkinter as tk
class ChatBot:
    def __init__(self, name):
        self.name = name

    def greet(self):
        return f"Hello! I am {self.name}, your mood chatbot."

    def respond(self, mood):
        mood = mood.strip().lower()
        if mood == "sad":
            return "What happened?"
        elif mood == "happy":
            return "What made you happy?"
        else:
            return "I can only understand 'sad' or 'happy'. Please try again."
# Create an instance of ChatBot
bot = ChatBot("MoodBot")
print(bot.greet())