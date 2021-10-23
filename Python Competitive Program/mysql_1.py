import mysql.connector
mydb=mysql.connector.connect(host='localhost',user='root',password='Mishra@21')
cur=mydb.cursor()
cur.execute("show databases")

for i in cur:
    print(i)



