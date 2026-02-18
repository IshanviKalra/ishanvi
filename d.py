class Dog:
    def speak(self):
        return "Bark!"
class Cat:
    def speak(self):
        return "Meow!"
def make_it_talk(animal):
    print(animal.speak())
my_dog = Dog()
my_cat = Cat()

make_it_talk(my_dog)
make_it_talk(my_cat)