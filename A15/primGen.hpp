
void Assignment15::createBoxMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
    
    float tWidth = 1024.0f;
    float tHeigth = 512.0f;
    float bLength = 1;
    float bDepth = bLength / 3.7f;

    int n = vDef.size();

    // Left face ok
    vDef.push_back({ { -bLength, -bLength, -bDepth }, { 1.0f, 0.0f, 0.0f }, { 0.0f / tWidth, 415.0f / tHeigth } });
    vDef.push_back({ { -bLength, -bLength, bDepth }, { 1.0f, 0.0f, 0.0f }, { 92.0f / tWidth, 413.0f / tHeigth } });
    vDef.push_back({ { -bLength, bLength, -bDepth }, { 1.0f, 0.0f, 0.0f }, { 0.0f / tWidth, 96.0f / tHeigth } });
    vDef.push_back({ { -bLength, bLength, bDepth }, { 1.0f, 0.0f, 0.0f }, { 92.0f / tWidth, 96.0f / tHeigth } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Right face
    vDef.push_back({ { bLength, -bLength, -bDepth }, { 1.0f, 0.0f, 0.0f }, { 536.0f / tWidth, 415.0f / tHeigth } });
    vDef.push_back({ { bLength, -bLength, bDepth }, { 1.0f, 0.0f, 0.0f }, { 445.0f / tWidth, 413.0f / tHeigth } });
    vDef.push_back({ { bLength, bLength, -bDepth }, { 1.0f, 0.0f, 0.0f }, { 536.0f / tWidth, 96.0f / tHeigth } });
    vDef.push_back({ { bLength, bLength, bDepth }, { 1.0f, 0.0f, 0.0f }, { 445.0f / tWidth, 96.0f / tHeigth } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Back face ok
    vDef.push_back({ { -bLength, -bLength, -bDepth }, { 0.0f, 0.0f, 1.0f }, { 887.0f / tWidth, 415.0f / tHeigth } });
    vDef.push_back({ { -bLength, bLength, -bDepth }, { 0.0f, 0.0f, 1.0f }, { 887.0f / tWidth, 96.0f / tHeigth } });
    vDef.push_back({ { bLength, -bLength, -bDepth }, { 0.0f, 0.0f, 1.0f }, { 540.0f / tWidth, 413.0f / tHeigth } });
    vDef.push_back({ { bLength, bLength, -bDepth }, { 0.0f, 0.0f, 1.0f }, { 540.0f / tWidth, 96.0f / tHeigth } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Front face
    vDef.push_back({ { -bLength, -bLength, bDepth }, { 0.0f, 0.0f, 1.0f }, { 96.0f / tWidth, 415.0f / tHeigth } });
    vDef.push_back({ { -bLength, bLength, bDepth }, { 0.0f, 0.0f, 1.0f }, { 96.0f / tWidth, 96.0f / tHeigth } });
    vDef.push_back({ { bLength, -bLength, bDepth }, { 0.0f, 0.0f, 1.0f }, { 442.0f / tWidth, 413.0f / tHeigth } });
    vDef.push_back({ { bLength, bLength, bDepth }, { 0.0f, 0.0f, 1.0f }, { 442.0f / tWidth, 96.0f / tHeigth } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Bottom face
    vDef.push_back({ { -bLength, -bLength, -bDepth }, { 0.0f, 1.0f, 0.0f }, { 96.0f / tWidth, 512.0f / tHeigth } });
    vDef.push_back({ { -bLength, -bLength, bDepth }, { 0.0f, 1.0f, 0.0f }, { 96.0f / tWidth, 421.0f / tHeigth } });
    vDef.push_back({ { bLength, -bLength, -bDepth }, { 0.0f, 1.0f, 0.0f }, { 442.0f / tWidth, 512.0f / tHeigth } });
    vDef.push_back({ { bLength, -bLength, bDepth }, { 0.0f, 1.0f, 0.0f }, { 442.0f / tWidth, 421.0f / tHeigth } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Upper face

    vDef.push_back({ { -bLength, bLength, -bDepth }, { 0.0f, 1.0f, 0.0f }, { 96.0f / tWidth, 0.0f / tHeigth } });
    vDef.push_back({ { -bLength, bLength, bDepth }, { 0.0f, 1.0f, 0.0f }, { 96.0f / tWidth, 90.0f / tHeigth } });
    vDef.push_back({ { bLength, bLength, -bDepth }, { 0.0f, 1.0f, 0.0f }, { 442.0f / tWidth, 0.0f / tHeigth } });
    vDef.push_back({ { bLength, bLength, bDepth }, { 0.0f, 1.0f, 0.0f }, { 442.0f / tWidth, 90.0f / tHeigth } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);
   }

#define M_PI 3.141595f
void Assignment15::createSphereMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
    uint32_t numRings = 32, numV = 256;
    float uCoordStep = 1.0f / static_cast<float>(numV);
    float vCoordStep = 1.0f / static_cast<float>(numRings);
    float x, y, z;

    float InitHeightAngle = glm::radians(180.0f / static_cast<float>(numRings)); // inclination
    float InitRingAngle = glm::radians(360.0f / static_cast<float>(numV));       // azimuth
    float currentRingAngle = 0, currentHeightAngle = InitHeightAngle;
    float currentUCoord = 0, currentVCoord = vCoordStep;

    // Generate the vertices for the top cap
    for (uint32_t i = 0; i < numV + 1; i++) {
        x = sin(currentHeightAngle) * cos(currentRingAngle);
        z = sin(currentHeightAngle) * sin(currentRingAngle);
        y = cos(currentHeightAngle);

        vDef.push_back({glm::vec3(x, y, z),
                        glm::vec3(x, y, z),
                        glm::vec2(currentUCoord, currentVCoord)}); // vertex 0 - Position, Normal and uv

        currentRingAngle += InitRingAngle;
        currentUCoord += uCoordStep;
    }

    uint32_t firstVertex;
    // Generate internal rings
    for (uint32_t ring = 0; ring < numRings - 2; ring++) {
        currentHeightAngle += InitHeightAngle;
        currentRingAngle = 0;
        currentVCoord += vCoordStep;
        currentUCoord = 0;
        firstVertex = vDef.size();

        // Generate the vertices for each internal ring
        for (uint32_t i = 0; i < numV + 1; i++) {
            x = sin(currentHeightAngle) * cos(currentRingAngle);
            z = sin(currentHeightAngle) * sin(currentRingAngle);
            y = cos(currentHeightAngle);

            vDef.push_back({glm::vec3(x, y, z),
                            glm::vec3(x, y, z),
                            glm::vec2(currentUCoord, currentVCoord)}); // vertex 0 - Position, Normal and uv

            currentRingAngle += InitRingAngle;
            currentUCoord += uCoordStep;
        }

        // Generate indices for the internal rings
        for (uint32_t t = 0; t < numV; t++) {
            vIdx.push_back(firstVertex + t);
            vIdx.push_back(firstVertex - numV - 1 + t);
            vIdx.push_back(firstVertex - numV + t);
            vIdx.push_back(firstVertex + t);
            vIdx.push_back(firstVertex + t + 1);
            vIdx.push_back(firstVertex - numV + t);
        }
    }

    // Generate vertices for the bottom cap and their corresponding indices
    currentUCoord = 0;
    for (uint32_t t = 0; t < numV; t++) {
        vDef.push_back({glm::vec3(0.0f, 1.0f, 0.0f),
                        glm::vec3(0.0f, 1.0f, 0.0f),
                        glm::vec2(currentUCoord, 0.0f)});
        vIdx.push_back(vDef.size() - 1);
        vIdx.push_back(t);
        vIdx.push_back(t + 1);

        vDef.push_back({glm::vec3(0.0f, -1.0f, 0.0f),
                        glm::vec3(0.0f, -1.0f, 0.0f),
                        glm::vec2(currentUCoord, 1.0f)});
        vIdx.push_back(vDef.size() - 1);
        vIdx.push_back(firstVertex + t);
        vIdx.push_back(firstVertex + t + 1);

        currentUCoord += uCoordStep;
    }
}

