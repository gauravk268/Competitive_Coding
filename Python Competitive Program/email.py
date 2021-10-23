# MIME:- Multipurpose Internet Mail Extension


# importing libraries

import smtplib
from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
from email.mime.image import MIMEImage

message = MIMEMultipart()

message["Subject"] = "How are you?"
message["From"] = "ravi mishra"

# sender and receiver

sender = "navinmishra14@gmail.com"
receiver = "mishraravi179@gmail.com"

# username and receiver
username = sender
password = open("pass.txt").read()


# let's create a mail body

body = """
<h1>Hello there</h1>
<h2>good night.</h2>
<p> You are good....</p>
<h3>good morning...</h3>
"""

txt = MIMEText(body,"html")
message.attach(txt)

# let's attach an image

i = open("img.png","rb")  # rb ---> read binary mode

img = MIMEImage(i.read())
message.attach(img)

server = smtplib.SMTP("smtp.gmail.com",587)
server.starttls()

server.login(username,password)
server.sendmail(sender,receiver,message.as_string())

print("Mail Sent Successfully")




















