#!/usr/bin/python3

import uuid
from datetime import datetime
from models import storage


class BaseModel:
    t_format = "%Y-%m-%dT%H:%M:%S.%f"

    def __init__(self, *args,**kwargs):
        
        if not kwargs:
            self.id = str(uuid.uuid4())
            self.created_at = datetime.now()
            self.updated_at = self.created_at
            storage.new(self)
        
        else:
            for key, value in kwargs.items():
                if key == "created_at" or key == "updated_at":
                    value = datetime.strptime(kwargs[key], BaseModel.t_format)
                if key != "__class__":
                    setattr(self, key, value)
    
    def save(self):
        self.updated_at = datetime.now()
        storage.save()
        
    def to_dict(self):
        
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
        class_name = self.__class__.__name__
        return "[{}] ({}) {}".format(class_name, self.id, self.__dict__)