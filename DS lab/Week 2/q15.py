import pandas as pd
 
stud_data = {
 "Name":["Parthivi","Aditya","Karunesh"],
 "Height":["165","195","175"],
 "Qualification":["B.Tech","B.Arch","M.Comm"]
}

df = pd.DataFrame.from_dict(stud_data)
print("Data Frame: ")
print(df)

address = ["MIT","FoA","Thane"]
df.insert(len(df.columns),"Address",address)
print("Updated data Frame: ")
print(df)