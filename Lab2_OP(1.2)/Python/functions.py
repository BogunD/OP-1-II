import pickle
from datetime import *

def AddToFile(fileName):
    file = open(fileName, 'ab')
    products = []
    flag = True
    while flag:
        product = {
            "name":str(input("Name: ")),
            "firstDate":getFirstDate(),
            "lastDate":getLastDate()
        }
        products.append(product)
        ans = str(input("Continue?(Y/N) "))
        if ans == "N" or ans == "n":
            flag = False
    pickle.dump(products,file)
    file.close()
    return products

def add_to_pickle(fileName, item):
    with open(fileName, 'ab') as file:
        pickle.dump(item, file, pickle.HIGHEST_PROTOCOL)

def read_from_pickle(fileName):
    with open(fileName, 'rb') as file:
        try:
            while True:
                yield pickle.load(file)
        except EOFError:
            pass

def clearFile(file):
    clear_file = open(file,'wb')
    clear_file.close()

def WantToClear(file1, file2, file3):
    ans = input("Do you want to clear file? (Y/N) ")
    while ans != 'N' and ans != 'n' and ans != 'Y' and ans != 'y':
        ans = str(input("Incorrect answer.\nPress Y if you want to clear file, in another case press N: "))
    if ans == "Y" or ans == "y":
        clearFile(file1)
        clearFile(file2)
        clearFile(file3)

def isOverdue(product):
    today = date.today()
    dayToday = today.strftime("%d.%m.%Y")
    lastdate = product["lastDate"]
    t1 = datetime.strptime(dayToday, "%d.%m.%Y")
    t2 = datetime.strptime(lastdate, "%d.%m.%Y")
    day = t2-t1
    Days = day.days
    if Days < 0:
        return True
    else:
        return False

def datesDiff(product):
    firstdate = product["firstDate"]
    lastdate = product["lastDate"]
    t1 = datetime.strptime(firstdate, "%d.%m.%Y")
    t2 = datetime.strptime(lastdate, "%d.%m.%Y")
    day = t2-t1
    return day.days

def allDiffs(products):
    diffs = []
    for product in products:
        day = datesDiff(product)
        diffs.append(day)
    return diffs

def distrProds(fileP, fileL, products, diffs):
    file1 = open(fileP,'ab')
    file2 = open(fileL,'ab')
    perishProds = []
    longTProds = []
    for i in range(0, len(diffs)):
        if isOverdue(products[i]):
            continue
        else:
            if diffs[i] <=5:
                perishProds.append(products[i])
            else:
                longTProds.append(products[i])

    pickle.dump(perishProds,file1)
    pickle.dump(longTProds,file2)
    file2.close()
    file1.close()

def printNames(fileName):
    for items in read_from_pickle(fileName):
        for item in items:
            print(" # " + item["name"])

def isDateCorrect (date):
     try:
        datetime.strptime(date, '%d.%m.%Y')
        print('Ok')
     except Exception:
         print('Incorrect input')
         return False
def getFirstDate():
    date=input("Date of issue: ")
    while isDateCorrect(date) == False:
        date = input("Try again: ")
    return date

def getLastDate():
    date=input("Expiry date: ")
    while isDateCorrect(date) == False:
         date = input ("Try again: ")
    return date
