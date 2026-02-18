class student:
    def __init__(self, name, email_id, sap_id):
        self.name = name
        self.email_id = email_id
        self.sap_id = sap_id
s1 = student("Ishanvi", "ishanvi@example.com", "590025196") 
print(s1.name) # Ishanvi
print(s1.email_id) # ishanvi@example.com
print(s1.sap_id) # 590025196