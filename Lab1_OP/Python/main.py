from functions import*
text = inp_text()
print("Input:", "\n")
print(text)
name1 = "text.txt"
name2 = "text2.txt"
fill_file(text, name1)
new_text = edit_file(name1)
print("\nOutput:\n")
print(new_text)
fill_file(new_text, name2)


