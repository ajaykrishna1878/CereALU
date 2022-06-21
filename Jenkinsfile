pipeline {
  agent any
  stages {
    stage('Get PWD') {
      steps {
        sh 'pwd'
      }
    }
    stage('Run Makefile') {
      steps {
        sh 'make'
      }
    }
  }
}
