# Generated by Django 3.0.7 on 2020-06-22 21:00

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('Website', '0003_auto_20200622_2030'),
    ]

    operations = [
        migrations.AlterField(
            model_name='drone',
            name='deploy_pin',
            field=models.IntegerField(editable=False, unique=True),
        ),
    ]