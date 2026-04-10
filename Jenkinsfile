pipeline {
    agent any

    environment {
        BUILD_DIR = 'build'
    }

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Show Environment') {
            steps {
                sh '''
                    echo "Workspace: $WORKSPACE"
                    git --version || true
                    g++ --version || true
                    cmake --version || true
                '''
            }
        }

        stage('Configure') {
            steps {
                sh '''
                    cmake -S . -B ${BUILD_DIR}
                '''
            }
        }

        stage('Build') {
            steps {
                sh '''
                    cmake --build ${BUILD_DIR}
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                    ctest --test-dir ${BUILD_DIR} --output-on-failure
                '''
            }
        }
    }

    post {
        success {
            echo 'Build and tests passed.'
        }
        failure {
            echo 'Build or tests failed.'
        }
        always {
            archiveArtifacts artifacts: 'build/**/*', fingerprint: true, allowEmptyArchive: true
        }
    }
}