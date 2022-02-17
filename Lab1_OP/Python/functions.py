def inp_text():
    print("Enter lines. After line press enter.\nIf you want to finish typing, press ctrl+D")
    text = ""
    lines = []
    while True:
        try:
            line = input()
        except EOFError:
            break

        if line != chr(4):
            lines.append(line)
        else:
            break

    return lines
def fill_file(lines,file_name):
    f_fill = open(file_name, "w")
    for line in lines:
        f_fill.write(str(line)+"\n")
    f_fill.close()

def edit_file( file_name1):
    f1 = open(file_name1, "r")
    text = f1.read()
    lines2 = []
    lines3 = []
    lines = text.split("\n")
    for line in lines:
        size = len(line)//2 + 1
        if line[:1] == "#":
            lines2.append(line[1:size] + '!'+line[size:])

        else:
            lines3.append(line)
    lines3.pop()
    f1.close()
    return  lines3 + lines2

def print_list(listName):
    for line in listName:
        print(line)
