import pandas as pd
 
stud_data = {
 "Name":["Parthivi","Aditya","Karunesh"],
 "Height":["165","195","175"],
 "Qualification":["B.Tech","B.Arch","M.Comm"]
}

new1 = pd.DataFrame.from_dict(stud_data)
print("Data Frame: ")
print(new1)

address = ["MIT","FoA","Thane"]
stud_data.update({"Address":address})
 
print("Updated dictionary: ",stud_data)
new2 = pd.DataFrame.from_dict(stud_data)
print("Updated data Frame: ")
print(new2)