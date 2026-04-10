pipeline {
    agent any

    stages {
        stage('Checkout'){
            steps {
                checkout scm
        }

        stage('Test from GitHub') {
            steps {
                echo 'Hello, Jenkins! This is a test pipeline to build and test a C++ project using CMake.'
            }
        }

        stage('Show Environment Variables') {
            steps {
                bat '''
                echo Workspace: %WORKSPACE%
                git --version
                cmake --version
                '''
            }
        }
    }
}