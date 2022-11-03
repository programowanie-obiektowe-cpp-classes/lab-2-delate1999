#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
    public:
        ResourceManager() : resource()   {}

        ~ResourceManager(){
            delete &resource;
        }

        double get(){
            return resource.get();
        }

        ResourceManager(const ResourceManager& _resource_manager){
            resource = _resource_manager.resource;
        }

        ResourceManager operator=(const ResourceManager& _resource_manager){
            if(this != &_resource_manager){
                resource = _resource_manager.resource;
            }

            return *this;
        }

    private:
        Resource resource;
};
