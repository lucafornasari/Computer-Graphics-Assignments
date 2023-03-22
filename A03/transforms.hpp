

void SetupMatrices(Assignment03 *A) {
/**************
 Method Matrix(int N, glm::mat4 M) of object A,
 receives in N the number of the matrix that needs to be set, and the matrix in M
***************/

    /* Variable declaration */
    glm::mat4 S, Sp, Rx, Ry, Ryinv, T, Tinv;
	
	
	// To solve the puzzle: scale 2x proportionally, centered in (2,0,-3)
    T = glm::translate(glm::mat4(1), glm::vec3(2.0f, 0, -3.0f)); // Translation matrix
    Tinv = glm::inverse(T); // Inverse translation matrix
    Sp = glm::scale( glm::mat4(1), glm::vec3(2.0f));   // Proportional scale matrix
    S = T * Sp * Tinv;
    A->Matrix(1, S);
    
	// To solve the puzzle: scale 2x on an axis oriented 45 degrees between the x and z axis and passing through point (1,0,0)
    Ry = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0)); // Rotation matrix
    Ryinv = glm::inverse(Ry);
    T = glm::translate(glm::mat4(1), glm::vec3(1.0f, 0, 0));      // Translation matrix
    Tinv = glm::inverse(T);
    Sp = glm::scale( glm::mat4(1), glm::vec3(3,1,1));   // Proportional scale matrix
    S = T * Ry * Sp * Ryinv * Tinv;
	A->Matrix(2, S); // sets the matrix corresponding to piece 2

	// To solve the puzzle: find it yourself! Hint: compose a rotation around an arbitrary point with a translation
    Ry = glm::rotate(glm::mat4(1), glm::radians(45.0f), glm::vec3(0, 1, 0)); // Rotation matrix
    T = glm::translate(glm::mat4(1), glm::vec3(0.3, 0, 3.7));      // Translation matrix
    Tinv = glm::inverse(T); // Inverse translation matrix
    S = T * Ry * Tinv;
	A->Matrix(3, S); // sets the matrix corresponding to piece 3

	// To solve the puzzle: rotate 60 degree around the y axis, centered in (-1,0,-2)
    T = glm::translate(glm::mat4(1), glm::vec3(-1.0f, 0, -2.0f));
    Ry = glm::rotate(glm::mat4(1), glm::radians(60.0f), glm::vec3(0, 1.0f, 0));
    S = T*Ry*inverse(T);
	A->Matrix(4, S); // sets the matrix corresponding to piece 4

	// To solve the puzzle: rotate -90 degree around an arbitrary axis passing in (-1,0,0). The x axis can be aligned to this arbitrary direction with a rotation of -45 around the y axis.
    Ry = glm::rotate(glm::mat4(1), glm::radians(-45.0f), glm::vec3(0, 1, 0)); // Rotation matrix
    Rx = glm::rotate(glm::mat4(1), glm::radians(-90.0f), glm::vec3(1, 0, 0)); // Rotation matrix
    T = glm::translate(glm::mat4(1), glm::vec3(-1.0f, 0, 0));      // Translation matrix
    Tinv = glm::inverse(T);
    Ryinv = glm::inverse(Ry);
    S = T * Ry * Rx * Ryinv * Tinv;
	A->Matrix(5, S); // sets the matrix corresponding to piece 5

	// To solve the puzzle: find it yourself! Hint: compose a non-proportional scaling that halves the object along one of the main axes, centered in an arbitrary point, with a translation
    T = glm::translate(glm::mat4(1), glm::vec3(1, 0, 3.0f));      // Translation matrix
    Tinv = glm::inverse(T); // Inverse translation matrix
    Sp = glm::scale( glm::mat4(1), glm::vec3(.5, 1, 1));   // Proportional scale matrix
    S = T * Sp * Tinv;
	A->Matrix(6, S); // sets the matrix corresponding to piece 6

}
