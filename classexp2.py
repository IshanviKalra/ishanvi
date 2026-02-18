class Dog:
    kind = 'canine'
    def __init__(self, name):
        self.name = name
d = Dog('Fido')
e = Dog('Buddy')
print(d.kind) # shared by all dogs
print(e.kind) # shared by all dogs
print(d.name) # unique to d
print(e.name) # unique to e