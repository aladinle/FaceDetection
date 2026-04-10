pipeline {
    agent any

    stages 
    {
        stage('Checkout')
        {
            steps 
            {
                checkout scm
            }
        }

        // stage('Test from GitHub') 
        // {
        //     steps 
        //     {
        //         echo 'Hello, Jenkins! This is a test pipeline to build and test a C++ project using CMake.'
        //     }
        // }

        stage('Show Environment Variables') 
        {
            steps 
            {
                script 
                {
                    sh '''
                    echo Workspace: $WORKSPACE
                    git --version
                    which cmake || true
                    cmake --version
                    '''
                }
            }
        }

        stage('Debug') 
        {
            steps 
            {
                sh '''
                whoami
                hostname
                which cmake || echo "cmake NOT found"
                '''
            }
        }

        stage('Build') 
        {
            steps 
            {
                sh '''
                echo "Building the project..."

                # Create a build directory
                mkdir -p build
                cd build

                # Run CMake
                cmake ..

                # Build project
                cmake --build . -- -j$(nproc)

                echo "Build completed successfully!"
                '''
            }
        }
    }
}