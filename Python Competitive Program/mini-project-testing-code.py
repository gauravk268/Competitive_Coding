import speech_recognition as sr
r=sr.Recogniser()
with sr.Microphone() as source:
    print("Say something")
audio=r.listen(source)
print("Heard")

try:
    print("Sphinx thinks you said " +r.recognize_sphinx(audio))
except sr.UnknownValueError:
    print("SPhinx could not understand audio")
except sr.RequestError as e:
    print("Sphinx error;{0}".format(e))  

try:
    print("Google speech recognition thinks you said " +r.recognize_google(audio))
except sr.UnknownValueError :
    print("Google speech recognition could not understand audio")
except sr.RequestError as e:
    print("Could not request resukts from google speech recognition service; {0}".format(e))
    



    WIT_AI_KEY ="INSERT WIT.AI API KEY HERE"

try:
    print("Wit.ai thinks you said " + r.recognize(audio, key =WIT_AI_KEY))
    
except sr.UnknownValueError:
        print("Wit.ai cpould not understand audio")
except sr.RequestError as e:
            print("Could not request results from Wir.ai service; {0}".format(e))
            

            BING_KEY = "INSERT BING API KEY HERE"

try:
    print("Microsoft Bing Voice Recognition thinks you said " +r.recognize_bing(audio, key=BING_KEY))
except sr.UnknownValueError :
    print("Microsoft Bing Voice Recognition could not understand audio ")
except sr.RequestError as e:
    print("Could not request results from Microsoft Bing Voice Recognition service; {0}".format(e))


    AZURE_SPEECH_KEY ="INSERT AZURE SPEECH API KEY HERE"
    try:
            print("Microsoft Azure Speech thinks you said " +r.recognize_azure(audio, key=AZURE+SPEECH_KEY))
    except sr.UnknownValueError:
                print("Microsoft Azure Speech could not understand audio")
    except sr.RequestError as e:
                  print("Could not request results from Microsoft Azure Speech service; {0}".format(e))


HOUNDIFY_CLIENT_ID = "INSERT HOUNDIFY CLIENT ID HERE"
HOUNDIFY_CLIENT_KEY = "INSERT HOUNDIFY CLIENT KEY HERE"

try:
    print("Houndify thinks you said " + r.recognize.houndify(audio,client_id=HOUNDIFY_CLIENT_ID, client_key= HOUNDIFY_CLIENT_KEY))
except sr.UnknownValueError:
        print("Houndify could not understand audio")
except sr.RequestError as e:
                  print("Could not request results from Houndify service; {0}".format(e))


                  IBM_USERNAME="INSERT IBM SPEECH TO TEXT USERNAME HERE"
                  IBM_PASSWORD="INSERT IBM SPEECH TO TEXT PASSWORD HERE"


                  try:
                      print("IBM speech to text thinks " +r.recognize_ibm("audio.username=IBM_USERNAME", "password=IBM_PASSWORD"))
                  except sr.UnknownValueError : 
                      print("IBM speech to text could not understand audio")
                  except sr.RequestError as e:
                      print("Could not request results from IBM speech to text service; {0}".format(e))
