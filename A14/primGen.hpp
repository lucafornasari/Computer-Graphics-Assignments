void Assignment14::createCubeMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
    int n = vDef.size();
    int length = 1.0f;

    // Left face ok
    vDef.push_back({ { -1, -1, -1 }, { 1.0f, 0.0f, 0.0f } });
    vDef.push_back({ { -1, -1, 1 }, { 1.0f, 0.0f, 0.0f } });
    vDef.push_back({ { -1, 1, -1 }, { 1.0f, 0.0f, 0.0f } });
    vDef.push_back({ { -1, 1, 1 }, { 1.0f, 0.0f, 0.0f } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Right face
    vDef.push_back({ { 1, -1, -1 }, { 1.0f, 0.0f, 0.0f } });
    vDef.push_back({ { 1, -1, 1 }, { 1.0f, 0.0f, 0.0f } });
    vDef.push_back({ { 1, 1, -1 }, { 1.0f, 0.0f, 0.0f } });
    vDef.push_back({ { 1, 1, 1 }, { 1.0f, 0.0f, 0.0f } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Back face ok
    vDef.push_back({ { -1, -1, -1 }, { 0.0f, 0.0f, 1.0f } });
    vDef.push_back({ { -1, 1, -1 }, { 0.0f, 0.0f, 1.0f } });
    vDef.push_back({ { 1, -1, -1 }, { 0.0f, 0.0f, 1.0f } });
    vDef.push_back({ { 1, 1, -1 }, { 0.0f, 0.0f, 1.0f } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Front face
    vDef.push_back({ { -1, -1, 1 }, { 0.0f, 0.0f, 1.0f } });
    vDef.push_back({ { -1, 1, 1 }, { 0.0f, 0.0f, 1.0f } });
    vDef.push_back({ { 1, -1, 1 }, { 0.0f, 0.0f, 1.0f } });
    vDef.push_back({ { 1, 1, 1 }, { 0.0f, 0.0f, 1.0f } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Bottom face
    vDef.push_back({ { -1, -1, -1 }, { 0.0f, 1.0f, 0.0f } });
    vDef.push_back({ { -1, -1, 1 }, { 0.0f, 1.0f, 0.0f } });
    vDef.push_back({ { 1, -1, -1 }, { 0.0f, 1.0f, 0.0f } });
    vDef.push_back({ { 1, -1, 1 }, { 0.0f, 1.0f, 0.0f } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);

    n = vDef.size();

    // Upper face

    vDef.push_back({ { -1, 1, -1 }, { 0.0f, 1.0f, 0.0f } });
    vDef.push_back({ { -1, 1, 1 }, { 0.0f, 1.0f, 0.0f } });
    vDef.push_back({ { 1, 1, -1 }, { 0.0f, 1.0f, 0.0f } });
    vDef.push_back({ { 1, 1, 1 }, { 0.0f, 1.0f, 0.0f } });

    vIdx.push_back(n); vIdx.push_back(n + 1); vIdx.push_back(n + 2);
    vIdx.push_back(n + 1); vIdx.push_back(n + 2); vIdx.push_back(n + 3);
}

void Assignment14::createFunctionMesh(std::vector<Vertex> &vDef, std::vector<uint32_t> &vIdx) {
    const int numSteps = 100;
    const float stepSize = 6.0f / numSteps;

    vDef.clear();
    vIdx.clear();

    // Generate vertices and normals
    for (int xStep = 0; xStep <= numSteps; ++xStep) {
        for (int zStep = 0; zStep <= numSteps; ++zStep) {
            float x = -3.0f + xStep * stepSize;
            float z = -3.0f + zStep * stepSize;

            Vertex vertex;
            vertex.pos = glm::vec3(x, sin(x) * cos(z), z);

            // Calculate the normal vector
            glm::vec3 tangentX(stepSize, cos(x) * cos(z), 0.0f);
            glm::vec3 tangentZ(0.0f, -sin(x) * sin(z), stepSize);
            vertex.norm = glm::normalize(glm::cross(tangentX, tangentZ));

            vDef.push_back(vertex);
        }
    }

    // Generate indices for triangles
    for (int xStep = 0; xStep < numSteps; ++xStep) {
        for (int zStep = 0; zStep < numSteps; ++zStep) {
            int topLeft = xStep * (numSteps + 1) + zStep;
            int topRight = topLeft + 1;
            int bottomLeft = (xStep + 1) * (numSteps + 1) + zStep;
            int bottomRight = bottomLeft + 1;

            // Triangulate the quad formed by four vertices
            vIdx.push_back(topLeft);
            vIdx.push_back(bottomLeft);
            vIdx.push_back(bottomRight);

            vIdx.push_back(topLeft);
            vIdx.push_back(bottomRight);
            vIdx.push_back(topRight);
        }
    }
}

void Assignment14::createCylinderMesh(std::vector<Vertex>& vDef, std::vector<uint32_t>& vIdx) {
    uint32_t numV = 64;
    float initAngle = 360.0f / static_cast<float>(numV);
    float currAngle = 0;

    float cylinderRadius = 0.5; // Change the radius value here
    float cylinderHeight = 1.5; // Change the height value here
    
    // Center vertices
    vDef.push_back({{0.0f, 0.0f, 0.0f}, {0.0f, -1.0f, 0.0f}});
    vDef.push_back({{0.0f, cylinderHeight, 0.0f}, {0.0f, 1.0f, 0.0f}});

    for (uint32_t i = 0; i < numV; i++) {
        // Bottom vertices
        vDef.push_back({{cylinderRadius * cos(glm::radians(currAngle)), 0.0f, cylinderRadius * sin(glm::radians(currAngle))}, {0.0f, -1.0f, 0.0f}});
        vDef.push_back({{cylinderRadius * cos(glm::radians(currAngle)), 0.0f, cylinderRadius * sin(glm::radians(currAngle))}, {cos(glm::radians(currAngle)), 0.0f, sin(glm::radians(currAngle))}});

        // Top vertices
        vDef.push_back({{cylinderRadius * cos(glm::radians(currAngle)), cylinderHeight, cylinderRadius * sin(glm::radians(currAngle))}, {0.0f, 1.0f, 0.0f}});
        vDef.push_back({{cylinderRadius * cos(glm::radians(currAngle)), cylinderHeight, cylinderRadius * sin(glm::radians(currAngle))}, {cos(glm::radians(currAngle)), 0.0f, sin(glm::radians(currAngle))}});

        currAngle += initAngle;
    }

    // Create the indices for the triangles of the cylinder
    for (uint32_t i = 0; i < numV * 4 - 4; i = i + 4) {
        vIdx.push_back(0); vIdx.push_back(i + 2); vIdx.push_back(i + 6); // First triangle
        vIdx.push_back(1); vIdx.push_back(i + 4); vIdx.push_back(i + 8); // First triangle

        vIdx.push_back(i + 3); vIdx.push_back(i + 5); vIdx.push_back(i + 7); // First triangle
        vIdx.push_back(i + 7); vIdx.push_back(i + 9); vIdx.push_back(i + 5); // First triangle
    }

    vIdx.push_back(0); vIdx.push_back(vDef.size() - 4); vIdx.push_back(2);
    vIdx.push_back(1); vIdx.push_back(vDef.size() - 2); vIdx.push_back(4);

    vIdx.push_back(vDef.size() - 3); vIdx.push_back(vDef.size() - 1); vIdx.push_back(3);
    vIdx.push_back(5); vIdx.push_back(vDef.size() - 1); vIdx.push_back(3);
}
