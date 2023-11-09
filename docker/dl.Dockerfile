FROM ubuntu:latest
RUN apt-get update && apt-get install -y python3 python3-pip openmpi-bin openmpi-common libopenmpi-dev
RUN apt-get install -y git cmake default-jre
RUN pip install "dlio_benchmark @ git+https://github.com/argonne-lcf/dlio_benchmark.git"
RUN pip install git+https://github.com/hariharan-devarajan/dlio-profiler.git
RUN mkdir -p /dlio/data /dlio/output
ENV DLIO_PROFILER_ENABLE=0
RUN mpirun -n 2 --allow-run-as-root dlio_benchmark workload=resnet50 ++workload.dataset.data_folder=/dlio/data ++workload.output.folder=/dlio/output ++workload.workflow.generate_data=True ++workload.workflow.train=False
ENV DLIO_PROFILER_ENABLE=1
ENV DLIO_PROFILER_LOG_LEVEL=ERROR
ENV DLIO_PROFILER_INC_METADATA=1
RUN ls -al /dlio/output/
RUN dlio_benchmark workload=resnet50 ++workload.dataset.data_folder=/dlio/data ++workload.output.folder=/dlio/output ++workload.dataset.num_files_train=1
RUN ls -al /dlio/output/
RUN cat /dlio/output/.trace*.pfw | grep POSIX