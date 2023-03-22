#include <glm/gtx/transform2.hpp>

void SetupProjectionMatrices(Assignment04 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

	glm::mat4 S, Port, R1, R2;
    const float half_width = 10.0f;
    const float top = half_width / Ar;
    const float bottom = -top;
    const float near_plane = -50.0f;
    const float far_plane = 50.0f;
    const float ro = 0.5f;
    const float hx = -0.70f*ro;
    const float hy = hx;
	
    Port = glm::scale( glm::mat4(1), glm::vec3(1, -1, 1))*glm::ortho(-half_width, half_width, bottom, top, near_plane, far_plane);
	
	// Isometric projection
    R1 = glm::rotate(glm::mat4(1), glm::radians(-45.0f), glm::vec3(0, 1, 0));
    R2 = glm::rotate(glm::mat4(1), glm::radians(35.26f), glm::vec3(1, 0, 0));
    S = Port*R2*R1;
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Dimetric
    R2 = glm::rotate(glm::mat4(1), glm::radians(25.0f), glm::vec3(1, 0, 0));
    S = Port*R2*R1;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Trimetric
    R1 = glm::rotate(glm::mat4(1), glm::radians(-60.0f), glm::vec3(0, 1, 0));
    R2 = glm::rotate(glm::mat4(1), glm::radians(40.26f), glm::vec3(1, 0, 0));
    S = Port*R2*R1;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Cabinet
    R2 = glm::shearZ3D(glm::mat4(1),hx,hy);
    S = Port*R2;
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
