FROM ubuntu

RUN apt-get update && apt-get install -y \ 
    apt-utils \
    openssh-server \
    default-jre && \
    python3 && \
    apt-get clean && \ 
    ln -s /usr/bin/python3 /usr/bin/python && \
    apt-get install -y python-pip \
    pip install py4j \
    pip -V \
    python -V \
    python --version
RUN apt-get install -y curl
RUN echo -e "Installations done successfully"  >>~/.bashrc

#RUN update-rc.d ssh defaults && ssh-keygen -f ~/.ssh/id_rsa -t rsa  -N '' && cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys
#COPY authorized_keys / ~/.ssh/authorized_keys
RUN ssh-keygen -A
RUN mkdir /var/run/sshd && chmod 755 /var/run/sshd
#RUN apt-get install -y curl
RUN curl https://www-us.apache.org/dist/spark/spark-2.4.4/spark-2.4.4-bin-hadoop2.7.tgz >spark-2.4.4.tgz 
RUN tar -xvf spark-2.4.4.tgz -C /usr/ && rm spark-2.4.4.tgz
COPY greesh.txt /
COPY wordcountspark.py /
RUN service ssh start
EXPOSE 22


