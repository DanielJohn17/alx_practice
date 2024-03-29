#!/usr/bin/python3
"""Module for BaseModel"""

import uuid
from datetime import datetime
from models import storage
from sqlalchemy.ext.declarative import declarative_base
from sqlalchemy import String, Column, DateTime


Base = declarative_base()

class BaseModel:
    """Represents the BaseModel of the HBnB project."""

    t_format = "%Y-%m-%dT%H:%M:%S.%f"
    id = Column(String(60), unique=True, primary_key=True, nullable=False)
    created_at = Column(DateTime, nullable=False, default=datetime.utcnow())
    updated_at = Column(DateTime, nullable=False, default=datetime.utcnow())

    def __init__(self, *args, **kwargs):
        """Initialize a new BaseModel.
        Args:
            *args (any): Unused.
            **kwargs (dict): Key/value pairs of attributes.
        """
        if not kwargs:
            self.id = str(uuid.uuid4())
            self.created_at = datetime.now()
            self.updated_at = self.created_at

        else:
            for key, value in kwargs.items():
                if key == "created_at" or key == "updated_at":
                    value = datetime.strptime(kwargs[key], BaseModel.t_format)
                if key != "__class__":
                    setattr(self, key, value)
            if "id" not in kwargs:
                self.id = str(uuid.uuid4())
            if "created_at" not in kwargs:
                self.created_at = datetime.now()
            if "updated_at" not in kwargs:
                self.updated_at = datetime.now()

    def save(self):
        """Update updated_at with the current datetime."""
        self.updated_at = datetime.now()
        storage.new(self)
        storage.save()

    def to_dict(self):
        """Return the dictionary of the BaseModel instance.
        Includes the key/value pair __class__ representing
        the class name of the object.
        """
        n_dict = {}

        for key, value in self.__dict__.items():
            if key == "created_at" or key == "updated_at":
                n_dict[key] = value.strftime(BaseModel.t_format)
            else:
                if not value:
                    pass
                else:
                    n_dict[key] = value

        n_dict["__class__"] = self.__class__.__name__

        return n_dict

    def __str__(self):
        """Return the print/str representation of the BaseModel instance."""
        class_name = self.__class__.__name__
        return "[{}] ({}) {}".format(class_name, self.id, self.__dict__)
    
    def delete(self):
        """delete object."""
        storage.delete(self)
