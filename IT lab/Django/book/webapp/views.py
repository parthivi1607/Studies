from django.shortcuts import render

# Create your views here.

def index(request):
    return render(request, 'home.html')

def publisher(request):
    return render(request, 'publisher.html')

def metadata(request):
    return render(request, 'metadata.html')
    
def reviews(request):
    return render(request, 'reviews.html')