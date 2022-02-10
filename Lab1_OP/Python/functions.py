def inp_text():
    text = ""
    lines = []
    while True:
        line = str(input(""))
        if line:
            lines.append(line)
        else:
            break
    text = '\n'.join(lines)
    return text

def fill_file(text,file_name):
    f_fill = open(file_name, "w")
    f_fill.write(text)
    f_fill.close()

def edit_file( file_name1):
    f1 = open(file_name1, "r")
    text = f1.read()
    lines2 = []
    lines3 = []
    lines = text.split("\n")
    text = ""
    newtext = ""
    for line in lines:
        size = len(line)//2 + 1
        if line[:1] == "#":
            lines2.append(line[1:size] + '!'+line[size:])
            newtext = "\n".join(lines2)
        else:
            lines3.append(line)
            text = "\n".join(lines3)
    return text + "\n" +newtext
