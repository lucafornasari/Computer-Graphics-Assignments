

void SetupProjectionMatrices(Assignment05 *A, float Ar) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

    glm::mat4 S;
    const float near_plane = 0.1f;
    const float far_plane = 50.0f;
    float FovY, FovX;
	
	
	// Fov-y = 60 deg
    FovY = glm::radians(60.0f);
    S = glm::perspective(FovY, Ar, near_plane, far_plane);
    S[1][1] *= -1;
	A->Matrix(1, S); // sets the matrix corresponding to piece 1

	// Fov-y = 105 deg
    FovY = glm::radians(105.0f);
    S = glm::perspective(FovY, Ar, near_plane, far_plane);
    S[1][1] *= -1;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// Fov-y = 25 deg
    FovY = glm::radians(25.0f);
    S = glm::perspective(FovY, Ar, near_plane, far_plane);
    S[1][1] *= -1;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// Right View, Fov-x = 45 deg
    FovY = glm::radians(45.0f);
    float t = near_plane * tan(FovY / 2.0f);
    float b = -t;
    float l = 0.0f;
    float r = 2.0f * Ar * t;
    S = glm::scale(glm::mat4(1), glm::vec3(1,-1,1)) * glm::frustum(l, r, b, t, near_plane, far_plane);
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

}
