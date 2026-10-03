import os
path = os.getcwd()
# print(path)
files = os.listdir(path)
with open("codebook.tex",'r', encoding="UTF-8") as op:
    lines = op.readlines()
    for line in lines:
        if line == "%sectionstart":
        
with open("output.txt", 'w', encoding="UTF-8") as op:
    for file in files:
        if not os.path.isdir(file):
            continue

        op.write("\\section{{{a}}}\n".format(a = file))
        tmp = os.listdir(file)
        for filename in tmp:
            op.write("    \\subsection{{{a}}}\n".format(a = filename.replace(".cpp", "")))
            op.write("    \\lstinputlisting{{{filepath}}}\n".format(filepath = "/".join([file, filename])))
            op.write('\n')
            

