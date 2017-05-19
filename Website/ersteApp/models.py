from django.db import models

# Create your models here.
class Stimmen(models.Model):
    Parteiname = models.CharField(max_length=30)
    Stimmen = models.IntegerField()
