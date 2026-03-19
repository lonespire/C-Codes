#!/usr/bin/env python3
"""
websearch wrapper for OpenClaw
自动区分国内外搜索引擎，使用不同网络配置
"""

import subprocess
import sys
import argparse

# 代理配置
PROXY_SOCKS5 = "socks5://127.0.0.1:7890"
NO_PROXY = "none"

# 搜索引擎分类
ENGINES_FOREIGN = ["google", "brave", "yahoo", "duckduckgo", "mojeek", "startpage", "presearch"]
ENGINES_DOMESTIC = ["baidu", "bing"]

def determine_proxy(engines):
    """
    根据搜索引擎类型决定是否使用代理
    """
    if not engines:
        return NO_PROXY
    
    engines_lower = engines.lower()
    
    for foreign in ENGINES_FOREIGN:
        if foreign in engines_lower:
            return PROXY_SOCKS5
    
    return NO_PROXY

def main():
    parser = argparse.ArgumentParser(description='智能搜索引擎包装器')
    parser.add_argument('query', help='搜索内容')
    parser.add_argument('-e', '--engines', help='搜索引擎列表')
    parser.add_argument('-n', '--max-results', type=int, default=10, help='每引擎结果数')
    parser.add_argument('--timeout', type=int, default=10, help='超时时间（秒）')
    parser.add_argument('--verbose', action='store_true', help='显示详细信息')
    
    args = parser.parse_args()
    
    # 确定是否使用代理
    proxy = determine_proxy(args.engines)
    
    # 构建webserp命令
    cmd = ['webserp', args.query]
    
    if args.engines:
        cmd.extend(['-e', args.engines])
    
    if args.max_results:
        cmd.extend(['-n', str(args.max_results)])
    
    if args.timeout:
        cmd.extend(['--timeout', str(args.timeout)])
    
    if args.verbose:
        cmd.append('--verbose')
    
    # 添加代理参数
    cmd.extend(['--proxy', proxy])
    
    print(f"使用代理: {proxy}")
    print(f"执行命令: {' '.join(cmd)}")
    print()
    
    # 执行搜索
    try:
        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=args.timeout + 5
        )
        
        print(result.stdout)
        if result.stderr:
            print(result.stderr, file=sys.stderr)
        
        return result.returncode
    
    except subprocess.TimeoutExpired:
        print("搜索超时", file=sys.stderr)
        return 1
    except Exception as e:
        print(f"搜索出错: {e}", file=sys.stderr)
        return 1

if __name__ == '__main__':
    sys.exit(main())
