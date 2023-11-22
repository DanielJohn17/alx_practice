#!/usr/bin/python3
"""__init__ magic method for models directory"""
from os import getenv
from models.engine.db_storage import DBStorage
from models.engine.file_storage import FileStorage


if getenv("HBNB_TYPE_STORAGE") == "db":
    storage = DBStorage()
    storage.reload()
else:
    storage = FileStorage()
    storage.reload()
