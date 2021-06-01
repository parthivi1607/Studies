from django.conf.urls import url
from . import views

urlpatterns = [
    url('home', views.index, name='index'),
    url('publisher', views.publisher, name='publisher'),
    url('metadata', views.metadata, name='metadata'),
    url('reviews', views.reviews, name='reviews'),
]