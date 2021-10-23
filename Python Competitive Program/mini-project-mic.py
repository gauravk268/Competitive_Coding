import speech_recognition as sr
r=sr.Recogniser()

with sr.Microphone() as source:
    
    print("Say something")
audio=r.listen(source)

try:
    print("Google speech recognition thinks you said " +r.recognize_google(audio))
except sr.UnknownValueError :
    print("Google speech recognition could not understand audio")
except sr.RequestError as e:
    print("Could not request resukts from google speech recognition service; {0}".format(e))
