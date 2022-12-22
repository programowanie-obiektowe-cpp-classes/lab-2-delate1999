#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
    public:
        ResourceManager(){
            resource = new Resource;
        }

        ~ResourceManager(){
            delete resource;
        }

        ResourceManager(const ResourceManager& _resource_manager){
            resource = new Resource;
            *resource = *_resource_manager.resource;
        }

        ResourceManager operator=(const ResourceManager& _resource_manager){
            if(this != &_resource_manager){
                delete resource;
                resource = new Resource;
                *resource = *_resource_manager.resource;
            }

            return *this;
        }

        ResourceManager(ResourceManager&& other)
            : resource(nullptr)
        {
            resource = other.resource;
            other.resource = nullptr;
        }

        ResourceManager& operator=(ResourceManager&& other){
            if(this != &other){
                delete resource;
                resource = other.resource;
                other.resource = nullptr;
            }
            return *this;
        }

        double get(){
            return resource->get();
        }

    private:
        Resource *resource;
};
