#!/usr/bin/python3

import json
import os

class FileStorage:
    __file_path =  "file.json"
    __objects = {}
    
    def all(self):
        return FileStorage.__objects
    
    def new(self, obj):
        key = "{}.{}".format(obj.__class__.__name__, obj.id)
        FileStorage.__objects[key] = obj
        
    def save(self):
        o_dict = {}
        
        for key, value in FileStorage.__objects.items():
            o_dict[key] = value.to_dict()
            
        with open(FileStorage.__file_path, 'w') as f:
            json.dump(o_dict, f)
            
    def reload(self):
        from models.base_model import BaseModel
        
        classes_dct = {
            "BaseModel": BaseModel
        }
        
        if os.path.exists() is True:
            with open(FileStorage.__file_path, 'r') as f:
                for key, value in json.load(f).items():
                    self.new(classes_dct[value['__class__']](**value))