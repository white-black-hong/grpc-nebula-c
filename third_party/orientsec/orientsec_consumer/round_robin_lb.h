/*
 * Copyright 2019 Orient Securities Co., Ltd.
 * Copyright 2019 BoCloud Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 *    Author : heiden deng(dengjianquan@beyondcent.com)
 *    2017/08/03
 *    version 0.0.9
 *    round robin 负载均衡处理类声明
 */

#ifndef ORIENTSEC_GRPC_ROUNDROBIN_H
#define ORIENTSEC_GRPC_ROUNDROBIN_H

#include "orientsec_loadbalance.h"
#include<map>
#include<vector>

#ifdef __cplusplus
extern "C" {
#endif

	class round_robin_lb :
		public orientsec_grpc_loadbalance
	{
	public:
		round_robin_lb();
		~round_robin_lb();

		//void setProviders(std::map<std::string, std::vector<provider_t*> > *_providers);
		void set_providers(std::map<std::string, provider_t*> *_providers);
		void reset_cursor(const char* sn);

		int choose_subchannel(const char* sn, provider_t *provider, const int*nums);

		provider_t* choose_provider(const char* sn, int step = 0);
	private:
		//std::map<std::string, std::vector<provider_t*> > *providers;
		std::map<std::string, provider_t*> *providers;
		//某服务的选择的provider位置
		std::map<std::string, int> cursors;
		//某服务的选择的subchannle位置
		int subchannlecursors;
	};

#ifdef __cplusplus
}
#endif

#endif // !ORIENTSEC_GRPC_ROUNDROBIN_H



