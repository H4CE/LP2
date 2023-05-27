import re
import random


rules = {
    "greet": {
        "pattern": [r"Hi", r"Hello", r"Hey", r"Hola"],
        "response": ["Hello, How can I help you today?", "Namaste, How may I be of your servive"]
    },
    "book_table": {
        "pattern": [r"book a table", r"book table", r"reserve table", r"reserve a table", r"reservation"],
        "response": ["Sure, What is your preferred time for the reservation?", "That is great, what time your are planning to visit us?"]
    },
    "time": {
        "pattern": [r"pm", r"morning ", r"evening ", r"tomorrow", r"tonight"],
        "response": ["Wonderful! May I have your name, please?", "Excellent, we have plenty availability at the time you would visit us, Please tell me your name:"]
    },
    "name": {
        "pattern": [r"my name", r"I am"],
        "response": [" That is a great name, Would you like to confirm your booking now?", "Okay, so should I consider this as a confirmed booking?"]
    },
    "confirmation": {
        "pattern": [r"confirm", r"yes", r"sure go ahead", r"absolutely"],
        "response": ["Yayy! reservation is completed!!", "Reservation Confirmed!!, We look forward for welcoming you!"]
    },
    "end_of_chat": {
        "pattern": [r"thank you", r"bye", r"goodbye"],
        "response": ["Have a great day, Thank you for using Chatbot service", "Bye Bye, I look forward meeting you for another reservation"]
    },
    "default": {

        "pattern": [],
        "response": ["I could not understand what you are trying to say", "Please rephrase your request so that I can understand and serve you better"]
    }

}
YELLOW = '\033[96m'
RESET = '\033[0m'

def getResponse(userInput):
    for key,value in rules.items():
        patterns=value["pattern"]
        for pattern in patterns:
            if re.search(pattern,userInput,re.IGNORECASE):
                responses= value["response"]
                return random.choice(responses)
    return random.choice(rules["default"]["response"])
        

def chat():
    print("CHATBOT")
    while (True):
        userInput=input("User:")
        response=getResponse(userInput)
        if response in rules["end_of_chat"]["response"]:
            print(YELLOW + "chatbot:" + response + RESET)
            break
        else:
            print(YELLOW + "chatbot:" + response + RESET)
            
        
chat()