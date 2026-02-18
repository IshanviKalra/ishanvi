from datetime import datetime

class BankAccount:
    def __init__(self, name, balance):
        self.name = name
        self._account_type = "Saving"
        self.__balance = balance

    # Save data to file
    def save_data(self):
        try:
            with open("account.txt", "w") as f:
                f.write(f"{self.name},{self._account_type},{self.__balance}")
        except Exception as e:
            print("Error while saving data:", e)

    # Load data from file
    def load_data(self):
        try:
            with open("account.txt", "r") as f:
                data = f.read().split(",")
                self.name = data[0]
                self._account_type = data[1]
                self.__balance = int(data[2])
        except FileNotFoundError:
            print("File not found!")
        except ValueError:
            print("File data is corrupted!")
        except Exception as e:
            print("Error while loading:", e)

    # Deposit
    def deposit(self, amount):
        try:
            if amount <= 0:
                raise ValueError("Amount must be positive!")
            self.__balance += amount
            self.save_data()
            print(f"{amount} deposited successfully.")
        except Exception as e:
            print("Deposit error:", e)

    # Withdraw with timestamp
    def withdraw(self, amount):
        try:
            if amount <= 0:
                raise ValueError("Amount must be positive!")
            if amount > self.__balance:
                raise ValueError("Insufficient balance!")

            self.__balance -= amount

            # Timestamp
            now = datetime.now()
            timestamp = now.strftime("%Y-%m-%d %H:%M:%S")

            # Save transaction history
            with open("transactions.txt", "a") as f:
                f.write(f"Withdrawn: {amount} | Time: {timestamp}\n")

            self.save_data()
            print(f"{amount} withdrawn successfully at {timestamp}")

        except Exception as e:
            print("Withdraw error:", e)

    # Get balance
    def get_balance(self):
        return self.__balance


# -------- Execution Part --------

try:
    name = input("Enter account holder name: ")
    balance = int(input("Enter initial balance: "))

    acc = BankAccount(name, balance)
    acc.save_data()

    while True:
        print("\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Load Data\n5. Exit")
        choice = input("Enter your choice: ")

        if choice == "1":
            try:
                amt = int(input("Enter amount to deposit: "))
                acc.deposit(amt)
            except ValueError:
                print("Invalid input! Enter a number.")

        elif choice == "2":
            try:
                amt = int(input("Enter amount to withdraw: "))
                acc.withdraw(amt)
            except ValueError:
                print("Invalid input! Enter a number.")

        elif choice == "3":
            print("Current Balance:", acc.get_balance())

        elif choice == "4":
            acc.load_data()
            print("Data loaded from file.")

        elif choice == "5":
            print("Thank you!")
            break

        else:
            print("Invalid choice!")

except ValueError:
    print("Invalid initial balance input!")
except Exception as e:
    print("Unexpected error:", e)