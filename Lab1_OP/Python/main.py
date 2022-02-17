from functions import*
lines = inp_text()
print("I N P U T   T E X T:", "\n")
print_list(lines)
name1 = "text.txt"
name2 = "text2.txt"
fill_file(lines, name1)
new_lines = edit_file(name1)
print("\nO U T P U T   T E X T:\n")
print_list(new_lines)
fill_file(new_lines, name2)
