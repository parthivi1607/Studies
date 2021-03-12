import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_excel("German Credit.xlsx", sheet_name='Sheet1', header=0,  engine="openpyxl")
print(df.head())
print(df.tail())

plt.scatter(df['CreditAmount'],df['DurationOfCreditInMonths'])
plt.xlabel('CreditAmount')
plt.ylabel('DurationOfCreditInMonths')
plt.show()

df['CreditAmount'].hist() 
plt.show()  

plt.boxplot(df,notch=True)
plt.show()  

f = df['Creditability'].value_counts()  
f.plot(kind='bar')
plt.show() 

f.plot(kind='pie') 
plt.show()

f = pd.crosstab(df['Creditability'],df['DurationOfCreditInMonths'])  
f.plot(kind='bar') 
plt.show() 