#include <Rendering\Data\MeshData.h>

MeshData::MeshData()
{
    //TODO : A modifier lors de la prise en compte du chargement d'asset

    // Cube de taille 1 : de -0.5 à +0.5
    constexpr float h = 0.5f;

    vertices = {
        // Face avant (+Z)
        {{-h, -h,  h}, { 0,  0,  1}},
        {{ h, -h,  h}, { 0,  0,  1}},
        {{ h,  h,  h}, { 0,  0,  1}},
        {{-h,  h,  h}, { 0,  0,  1}},

        // Face arrière (-Z)
        {{ h, -h, -h}, { 0,  0, -1}},
        {{-h, -h, -h}, { 0,  0, -1}},
        {{-h,  h, -h}, { 0,  0, -1}},
        {{ h,  h, -h}, { 0,  0, -1}},

        // Face droite (+X)
        {{ h, -h,  h}, { 1,  0,  0}},
        {{ h, -h, -h}, { 1,  0,  0}},
        {{ h,  h, -h}, { 1,  0,  0}},
        {{ h,  h,  h}, { 1,  0,  0}},

        // Face gauche (-X)
        {{-h, -h, -h}, {-1,  0,  0}},
        {{-h, -h,  h}, {-1,  0,  0}},
        {{-h,  h,  h}, {-1,  0,  0}},
        {{-h,  h, -h}, {-1,  0,  0}},

        // Face supérieure (+Y)
        {{-h,  h,  h}, { 0,  1,  0}},
        {{ h,  h,  h}, { 0,  1,  0}},
        {{ h,  h, -h}, { 0,  1,  0}},
        {{-h,  h, -h}, { 0,  1,  0}},

        // Face inférieure (-Y)
        {{-h, -h, -h}, { 0, -1,  0}},
        {{ h, -h, -h}, { 0, -1,  0}},
        {{ h, -h,  h}, { 0, -1,  0}},
        {{-h, -h,  h}, { 0, -1,  0}}
    };

    indices = {
        // Avant
         0,  1,  2,
         2,  3,  0,

         // Arrière
          4,  5,  6,
          6,  7,  4,

          // Droite
           8,  9, 10,
          10, 11,  8,

          // Gauche
          12, 13, 14,
          14, 15, 12,

          // Haut
          16, 17, 18,
          18, 19, 16,

          // Bas
          20, 21, 22,
          22, 23, 20
    };
}
