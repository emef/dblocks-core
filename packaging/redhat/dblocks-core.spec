#
#    dblocks-core - Project
#
#    Copyright (c) the Contributors as noted in the AUTHORS file.       
#    This file is part of CZMQ, the high-level C binding for 0MQ:       
#    http://czmq.zeromq.org.                                            
#                                                                       
#    This Source Code Form is subject to the terms of the Mozilla Public
#    License, v. 2.0. If a copy of the MPL was not distributed with this
#    file, You can obtain one at http://mozilla.org/MPL/2.0/.           
#

Name:           dblocks-core
Version:        0.1.0
Release:        1
Summary:        project
License:        MIT
URL:            http://example.com/
Source0:        %{name}-%{version}.tar.gz
Group:          System/Libraries
BuildRequires:  automake
BuildRequires:  autoconf
BuildRequires:  libtool
BuildRequires:  pkg-config
BuildRequires:  systemd-devel
BuildRequires:  libsodium-devel
BuildRequires:  zeromq-devel
BuildRequires:  czmq-devel
BuildRoot:      %{_tmppath}/%{name}-%{version}-build

%description
dblocks-core project.

%package -n libdblocks_core0
Group:          System/Libraries
Summary:        project

%description -n libdblocks_core0
dblocks-core project.
This package contains shared library.

%post -n libdblocks_core0 -p /sbin/ldconfig
%postun -n libdblocks_core0 -p /sbin/ldconfig

%files -n libdblocks_core0
%defattr(-,root,root)
%doc COPYING
%{_libdir}/libdblocks_core.so.*

%package devel
Summary:        project
Group:          System/Libraries
Requires:       libdblocks_core0 = %{version}
Requires:       libsodium-devel
Requires:       zeromq-devel
Requires:       czmq-devel

%description devel
dblocks-core project.
This package contains development files.

%files devel
%defattr(-,root,root)
%{_includedir}/*
%{_libdir}/libdblocks_core.so
%{_libdir}/pkgconfig/libdblocks_core.pc

%prep
%setup -q

%build
sh autogen.sh
%{configure} --with-systemd
make %{_smp_mflags}

%install
make install DESTDIR=%{buildroot} %{?_smp_mflags}

# remove static libraries
find %{buildroot} -name '*.a' | xargs rm -f
find %{buildroot} -name '*.la' | xargs rm -f


%changelog
