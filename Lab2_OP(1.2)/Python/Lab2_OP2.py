from functions import *
print("Enter date in the format DD.MM.YYYY.")
fileMain = "NewFilePy.dat"
fileP = "Perishable.dat"
fileL = "Long_term.dat"
WantToClear(fileMain, fileP, fileL)
products = AddToFile(fileMain)
dateDiffs = allDiffs(products)
distrProds(fileP,fileL,products,dateDiffs)
print("A L L   P R O D U C T S: ")
printNames(fileMain)
print("P E R I S H A B L E:")
printNames(fileP)
print("L O N G - T E R M:")
printNames(fileL)