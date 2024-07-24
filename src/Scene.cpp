/* date = May 10, 2024 10:49 AM */

#include "Scene.h"
#include "renderer/RendererController.h"

namespace MiniMario {

    Entity *Scene::getEntity(size_t id) {
        for (Entity *e: this->entities) {
            if (e && e->getID() == id) {
                return e;
            }
        }

        // TODO: print error
        return nullptr;
    }

    void Scene::update(double dt) {
        this->uploadCamera();

        for (auto *e: this->entities) {
            e->update(dt);
        }
    }
    void Scene::stop() {
        for (const Entity *e: this->entities) {
            delete e;
        }

        this->entities.clear();
    }

    Renderer::Camera *Scene::getCamera() { return &this->camera; }

    void Scene::uploadCamera() {
        Math::Mat4 proj = this->camera.getPerspectiveMatrix();
        Math::Mat4 view = this->camera.getViewMatrix();
        Renderer::RendererController::get()->setProjection(proj);
        Renderer::RendererController::get()->setView(view);
    }
} // MiniMario